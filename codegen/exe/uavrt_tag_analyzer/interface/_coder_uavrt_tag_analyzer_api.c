/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * _coder_uavrt_tag_analyzer_api.c
 *
 * Code generation for function 'uavrt_tag_analyzer'
 *
 */

/* Include files */
#include "_coder_uavrt_tag_analyzer_api.h"
#include "_coder_uavrt_tag_analyzer_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;

emlrtContext emlrtContextGlobal = {
    true,                                                 /* bFirstTime */
    false,                                                /* bInitialized */
    131642U,                                              /* fVersionInfo */
    NULL,                                                 /* fErrorFunction */
    "uavrt_tag_analyzer",                                 /* fFunctionName */
    NULL,                                                 /* fRTCallStack */
    false,                                                /* bDebugMode */
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, /* fSigWrd */
    NULL                                                  /* fSigMem */
};

/* Function Declarations */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *filePath,
                               const char_T *identifier, char_T y_data[],
                               int32_T y_size[2]);

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               char_T y_data[], int32_T y_size[2]);

static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *FsRawInput,
                               const char_T *identifier);

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               char_T ret_data[], int32_T ret_size[2]);

/* Function Definitions */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = e_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *filePath,
                               const char_T *identifier, char_T y_data[],
                               int32_T y_size[2])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  d_emlrt_marshallIn(sp, emlrtAlias(filePath), &thisId, y_data, y_size);
  emlrtDestroyArray(&filePath);
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               char_T y_data[], int32_T y_size[2])
{
  f_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y_data, y_size);
  emlrtDestroyArray(&u);
}

static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  real_T ret;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 0U,
                          (const void *)&dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *FsRawInput,
                               const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(FsRawInput), &thisId);
  emlrtDestroyArray(&FsRawInput);
  return y;
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               char_T ret_data[], int32_T ret_size[2])
{
  static const int32_T dims[2] = {1, 200};
  int32_T iv[2];
  boolean_T bv[2] = {false, true};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "char", false, 2U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  ret_size[0] = iv[0];
  ret_size[1] = iv[1];
  emlrtImportArrayR2015b((emlrtConstCTX)sp, src, &ret_data[0], 1, false);
  emlrtDestroyArray(&src);
}

void uavrt_tag_analyzer_api(const mxArray *const prhs[4])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real_T FsRawInput;
  real_T centerFreqMHz;
  real_T tp;
  int32_T filePath_size[2];
  char_T filePath_data[200];
  st.tls = emlrtRootTLSGlobal;
  /* Marshall function inputs */
  FsRawInput = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "FsRawInput");
  tp = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "tp");
  centerFreqMHz = emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "centerFreqMHz");
  c_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "filePath", filePath_data,
                     filePath_size);
  /* Invoke the target function */
  uavrt_tag_analyzer(FsRawInput, tp, centerFreqMHz, filePath_data,
                     filePath_size);
}

void uavrt_tag_analyzer_atexit(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  uavrt_tag_analyzer_xil_terminate();
  uavrt_tag_analyzer_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void uavrt_tag_analyzer_initialize(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, NULL);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

void uavrt_tag_analyzer_terminate(void)
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (_coder_uavrt_tag_analyzer_api.c) */
