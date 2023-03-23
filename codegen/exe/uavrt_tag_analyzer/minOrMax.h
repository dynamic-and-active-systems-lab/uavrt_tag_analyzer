/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * minOrMax.h
 *
 * Code generation for function 'minOrMax'
 *
 */

#ifndef MINORMAX_H
#define MINORMAX_H

/* Include files */
#include "rtwtypes.h"
#include "uavrt_tag_analyzer_types.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
double b_maximum(const emxArray_real_T *x);

int c_maximum(const emxArray_creal_T *x, creal_T *ex);

double maximum(const double x_data[], const int x_size[2]);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (minOrMax.h) */
