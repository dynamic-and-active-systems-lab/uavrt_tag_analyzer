/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * quickselect.h
 *
 * Code generation for function 'quickselect'
 *
 */

#ifndef QUICKSELECT_H
#define QUICKSELECT_H

/* Include files */
#include "rtwtypes.h"
#include "uavrt_tag_analyzer_types.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
double quickselect(emxArray_real_T *v, int n, int vlen, int *nfirst,
                   int *nlast);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (quickselect.h) */
