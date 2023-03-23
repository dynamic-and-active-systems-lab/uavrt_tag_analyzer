/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * uavrt_tag_analyzer_emxutil.h
 *
 * Code generation for function 'uavrt_tag_analyzer_emxutil'
 *
 */

#ifndef UAVRT_TAG_ANALYZER_EMXUTIL_H
#define UAVRT_TAG_ANALYZER_EMXUTIL_H

/* Include files */
#include "rtwtypes.h"
#include "uavrt_tag_analyzer_types.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void emxEnsureCapacity_boolean_T(emxArray_boolean_T *emxArray,
                                        int oldNumel);

extern void emxEnsureCapacity_creal_T(emxArray_creal_T *emxArray, int oldNumel);

extern void emxEnsureCapacity_int32_T(emxArray_int32_T *emxArray, int oldNumel);

extern void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int oldNumel);

extern void emxFree_boolean_T(emxArray_boolean_T **pEmxArray);

extern void emxFree_creal_T(emxArray_creal_T **pEmxArray);

extern void emxFree_int32_T(emxArray_int32_T **pEmxArray);

extern void emxFree_real_T(emxArray_real_T **pEmxArray);

extern void emxInit_boolean_T(emxArray_boolean_T **pEmxArray,
                              int numDimensions);

extern void emxInit_creal_T(emxArray_creal_T **pEmxArray);

extern void emxInit_int32_T(emxArray_int32_T **pEmxArray, int numDimensions);

extern void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (uavrt_tag_analyzer_emxutil.h) */
