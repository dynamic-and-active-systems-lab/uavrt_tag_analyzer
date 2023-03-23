/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * _coder_uavrt_tag_analyzer_api.h
 *
 * Code generation for function 'uavrt_tag_analyzer'
 *
 */

#ifndef _CODER_UAVRT_TAG_ANALYZER_API_H
#define _CODER_UAVRT_TAG_ANALYZER_API_H

/* Include files */
#include "emlrt.h"
#include "tmwtypes.h"
#include <string.h>

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void uavrt_tag_analyzer(real_T FsRawInput, real_T tp, real_T centerFreqMHz,
                        char_T filePath_data[], int32_T filePath_size[2]);

void uavrt_tag_analyzer_api(const mxArray *const prhs[4]);

void uavrt_tag_analyzer_atexit(void);

void uavrt_tag_analyzer_initialize(void);

void uavrt_tag_analyzer_terminate(void);

void uavrt_tag_analyzer_xil_shutdown(void);

void uavrt_tag_analyzer_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (_coder_uavrt_tag_analyzer_api.h) */
