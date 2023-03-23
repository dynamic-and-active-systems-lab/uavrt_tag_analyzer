/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * diff.h
 *
 * Code generation for function 'diff'
 *
 */

#ifndef DIFF_H
#define DIFF_H

/* Include files */
#include "rtwtypes.h"
#include "uavrt_tag_analyzer_types.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void b_diff(const emxArray_real_T *x, emxArray_real_T *y);

void diff(const emxArray_real_T *x, emxArray_real_T *y);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (diff.h) */
