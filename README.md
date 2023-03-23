# uavrt_tag_analyzer

This program analyzes software defined radio data and extracts parameters associated with pulses. The pulse strength in the signals must me much higher than background noise and the signals must be within +/- 5kHz of the radio center frequency, but ideally would be withing +/- 2kHz. The program uses a basic threshold method to identify pulses and then calculates time differences between the rising edges of the pulses. Time differences are filtered for outliers using Matlab rmoutliers function using the mediam method. A report is generated that provides the frequency where the pulses were found, the mean interpulse duration, the interpulse standard deviation (jitter). The pulse duration mean and standard deviation are also reported.  

The inputs to the are the sample rate of the SDR data, the pulse duration (seconds), the SDR radio center frequency (MHz), and the file path to the data file. The SDR data is expected to be single precision floating point complex data. The sample rate must be divisible by 10,000. The raw data is decimated down to 10,000 Hz before processing.  

After compiling the exectuable using the provided codegen script, call the function with the following command
```
./uavrt_tag_analyzer 3000000 0.02 148.525 <PATH_TO>/test_data.bin
```
The output will look as follows:
```
Loading data...
Done.
Decimating data...
Decimating data...
Decimating data...
Decimating data...
Decimating data...
Done.
---------TAG REPORT---------
Radio Frequency:       148.524994 MHz
Pulse Frequency:       148.527331 MHz
Frequency Deviation:   2337.246531 Hz
Interpulse Time:       1.374248 s
Interpulse Time Stdev: 0.000147 s
Pulse Mean Duration:   0.017036 s
Pulse Duration Stdev:  0.000049 s
----------------------------

```
