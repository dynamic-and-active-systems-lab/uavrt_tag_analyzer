/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * _coder_uavrt_tag_analyzer_mex.c
 *
 * Code generation for function 'uavrt_tag_analyzer'
 *
 */

/* Include files */
#include "_coder_uavrt_tag_analyzer_mex.h"
#include "_coder_uavrt_tag_analyzer_api.h"

/* Function Definitions */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  (void)plhs;
  mexAtExit(&uavrt_tag_analyzer_atexit);
  /* Module initialization. */
  uavrt_tag_analyzer_initialize();
  /* Dispatch the entry-point. */
  uavrt_tag_analyzer_mexFunction(nlhs, nrhs, prhs);
  /* Module termination. */
  uavrt_tag_analyzer_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL, "UTF-8", true);
  return emlrtRootTLSGlobal;
}

void uavrt_tag_analyzer_mexFunction(int32_T nlhs, int32_T nrhs,
                                    const mxArray *prhs[4])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 4) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 4, 4,
                        18, "uavrt_tag_analyzer");
  }
  if (nlhs > 0) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 18,
                        "uavrt_tag_analyzer");
  }
  /* Call the function. */
  uavrt_tag_analyzer_api(prhs);
}

/* End of code generation (_coder_uavrt_tag_analyzer_mex.c) */
