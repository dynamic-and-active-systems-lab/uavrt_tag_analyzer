/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * decimate.h
 *
 * Code generation for function 'decimate'
 *
 */

#ifndef DECIMATE_H
#define DECIMATE_H

/* Include files */
#include "rtwtypes.h"
#include "uavrt_tag_analyzer_types.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void decimate(const emxArray_creal_T *idata, unsigned int r,
              emxArray_creal_T *y);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (decimate.h) */
