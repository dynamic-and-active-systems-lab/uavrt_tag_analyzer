% UAVRT_TAG_ANALYZER_SCRIPT   Generate executable uavrt_tag_analyzer from
%  uavrt_tag_analyzer.
% 
% Script generated from project 'uavrt_tag_analyzer.prj' on 23-Mar-2023.
% 
% See also CODER, CODER.CONFIG, CODER.TYPEOF, CODEGEN.

%% Create configuration object of class 'coder.CodeConfig'.
cfg = coder.config('exe','ecoder',false);
cfg.HardwareImplementation.ProdEqTarget = false;
cfg.TargetLang = 'C';
cfg.GenCodeOnly = true;
cfg.CustomInclude = { '/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/CODE_PLAYGROUND/uavrt_tag_analyzer/custom_mains' };
cfg.CustomSource = { '/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/CODE_PLAYGROUND/uavrt_tag_analyzer/custom_mains/main.c' };
cfg.GenerateExampleMain = 'DoNotGenerate';
cfg.GenerateMakefile = false;
cfg.GenerateReport = true;
cfg.MaxIdLength = 1024;
cfg.ReportPotentialDifferences = false;
cfg.RuntimeChecks = true;

%% Define argument types for entry-point 'uavrt_tag_analyzer'.
ARGS = cell(1,1);
ARGS{1} = cell(4,1);
ARGS{1}{1} = coder.typeof(0);
ARGS{1}{2} = coder.typeof(0);
ARGS{1}{3} = coder.typeof(0);
ARGS{1}{4} = coder.typeof('X',[1 200],[0 1]);

%% Invoke MATLAB Coder.
codegen -config cfg uavrt_tag_analyzer -args ARGS{1}

