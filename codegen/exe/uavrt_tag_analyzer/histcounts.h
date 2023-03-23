/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * histcounts.h
 *
 * Code generation for function 'histcounts'
 *
 */

#ifndef HISTCOUNTS_H
#define HISTCOUNTS_H

/* Include files */
#include "rtwtypes.h"
#include "uavrt_tag_analyzer_types.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void histcounts(const emxArray_real_T *x, double n_data[], int n_size[2],
                double edges_data[], int edges_size[2]);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (histcounts.h) */
