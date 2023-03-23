function [] = uavrt_tag_analyzer(FsRawInput, tp, centerFreqMHz, filePath)
%UNTITLED3 Summary of this function goes here
%   Detailed explanation goes here

FsRaw = uint32(FsRawInput);
Fs = 10000;

%Debugging
% fprintf('FsRawInput %f \n',FsRawInput)
% fprintf('FsRaw %u \n',FsRaw)
% fprintf('tp %f \n',tp)
% fprintf('centerFreqMHz %f \n',centerFreqMHz)
% fprintf('filePath %s \n',filePath)
%

if mod(FsRaw, uint32(Fs))~=0
    fprintf('UAV-RT: Sample rate must be divisible by 10000.\n')
    return
end

if tp <= 0
    fprintf('UAV-RT: Pulse duration must be greater than 0.\n')
    return
end

if FsRaw <= 0
    fprintf('UAV-RT: Sample rate must be greater than 0.\n')
    return
end

if 1/FsRaw >= tp
    fprintf('UAV-RT: Sample period (1/Fs) be greater than pulse duration.\n')
    return
end

fprintf('Loading data...\n')
fid = fopen(filePath);
if fid ~= -1
    dataRaw = fread(fid,'single');
    fprintf('Done.\n')
else
    fprintf('UAV-RT: Error opening file at path provided.\n')
    return
end
if mod(dataRaw,2)~=0
    dataRaw(end) = [];
end

n_samps = numel(dataRaw)/2;

dataComplex   = complex(single(zeros(n_samps,1)));

dataDecimated = complex(single(zeros(n_samps,1)));

dataComplex = dataRaw(1:2:end-1)+1i*dataRaw(2:2:end);

decimationFactorList = factor(FsRaw / uint32(Fs));

n_decimationFactors = numel(decimationFactorList);

dataDecimated = dataComplex;
for i = 1:n_decimationFactors
    fprintf('Decimating data...\n')
    dataDecimated = decimate(dataDecimated, decimationFactorList(i), 'fir');
end
%Level for max out at 1;
dataDecimated = dataDecimated/max(abs(dataDecimated));
fprintf('Done.\n')

% n_pulse = Fs * tp;
% rectWind = rectwin(n_pulse);
% n_overlap = floor(0.5 * n_pulse);
% fprintf('Computing STFT...\n')
% [s,f,t] = stft(dataDecimated,Fs,Window=rectWind,OverlapLength=n_overlap,FFTLength=n_pulse);
% fprintf('Done.\n')

n_dec = length(dataDecimated);
dataAbsDecimated = abs(dataDecimated);
[~,edges] = histcounts(dataAbsDecimated,10);
threshold = edges(8);
dataThresholded = dataAbsDecimated;
dataThresholded(dataThresholded >= threshold) = 1;
dataThresholded(dataThresholded < threshold) = 0;

t = 1/Fs*(0:n_dec-1);
%figure; 
%plot(t, dataThresholded)
%hold on; plot(t,dataAbsDecimated/max(dataAbsDecimated))
transitions = diff(dataThresholded);

dt = diff(t(transitions == 1));
%dtEnd = diff(t(transitions == -1));
%dtMode = mode(round(dtStart*100)/100);

tPulseStart = t(transitions == 1);
tPulseEnd = t(transitions == -1);
pulseDurRecord = zeros(size(tPulseStart));
for i = 1:numel(tPulseStart)
    ind = find(tPulseEnd > tPulseStart(i),1,'first');
    if ~isnan(ind)
        tNextTransition = tPulseEnd(ind);
        pulseDur = tNextTransition - tPulseStart(i);
        if pulseDur <= 2*tp & pulseDur >= 1/2*tp%Filter for weird transitions that cause huge or small pulse durations. 
            pulseDurRecord(i) = pulseDur;
        else
            pulseDurRecord(i) = NaN;
        end
    else
        pulseDurRecord(i) = NaN;

    end
end
pulseDurRecord(isnan(pulseDurRecord)) = [];
%This was cutting out points that should be included. The pulse duration
%check in the for loop should accomplish filtering out really large tp
%values
%pulseDurRecordClean = rmoutliers(pulseDurRecord,'median');

pulseDurMean = mean(pulseDurRecord);
pulseDurStd = std(pulseDurRecord);

dtClean = rmoutliers(dt,'median');

dtStd  = std(dtClean);
dtMean = mean(dtClean);

pulseBool = logical(dataThresholded);
pulseOnly = dataDecimated(pulseBool);

pulseFFT = fftshift(fft(pulseOnly));
[~, maxFFTInd]= max(pulseFFT);
n_pulseOnly = length(pulseOnly);
f = (-n_pulseOnly/2:n_pulseOnly/2-1)/n_pulseOnly*Fs;
peakFreq = f(maxFFTInd);

pulseFreqMHz = centerFreqMHz + peakFreq/1e6;
fprintf('---------TAG REPORT---------\n', centerFreqMHz)
fprintf('Radio Frequency:       %.6f MHz\n', centerFreqMHz)
fprintf('Pulse Frequency:       %.6f MHz\n', pulseFreqMHz)
fprintf('Frequency Deviation:   %.6f Hz\n', (pulseFreqMHz - centerFreqMHz)*1e6)
fprintf('Interpulse Time:       %.6f s\n', dtMean)
fprintf('Interpulse Time Stdev: %.6f s\n', dtStd)
fprintf('Pulse Mean Duration:   %.6f s\n', pulseDurMean)
fprintf('Pulse Duration Stdev:  %.6f s\n', pulseDurStd)
fprintf('----------------------------\n', centerFreqMHz)

% if ~isdeployed
%     first5SecInds = 1:(5*Fs);
%     sound(real(dataDecimated(first5SecInds)),Fs)
% end

end