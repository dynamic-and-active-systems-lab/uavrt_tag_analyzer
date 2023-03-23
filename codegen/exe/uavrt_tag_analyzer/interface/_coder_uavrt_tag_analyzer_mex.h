/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * _coder_uavrt_tag_analyzer_mex.h
 *
 * Code generation for function 'uavrt_tag_analyzer'
 *
 */

#ifndef _CODER_UAVRT_TAG_ANALYZER_MEX_H
#define _CODER_UAVRT_TAG_ANALYZER_MEX_H

/* Include files */
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
MEXFUNCTION_LINKAGE void mexFunction(int32_T nlhs, mxArray *plhs[],
                                     int32_T nrhs, const mxArray *prhs[]);

emlrtCTX mexFunctionCreateRootTLS(void);

void uavrt_tag_analyzer_mexFunction(int32_T nlhs, int32_T nrhs,
                                    const mxArray *prhs[4]);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (_coder_uavrt_tag_analyzer_mex.h) */
