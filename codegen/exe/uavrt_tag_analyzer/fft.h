/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * fft.h
 *
 * Code generation for function 'fft'
 *
 */

#ifndef FFT_H
#define FFT_H

/* Include files */
#include "rtwtypes.h"
#include "uavrt_tag_analyzer_types.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void b_fft(const double x_data[], const int x_size[2], double varargin_1,
           creal_T y_data[], int y_size[2]);

void c_fft(const emxArray_creal_T *x, emxArray_creal_T *y);

void fft(const double x_data[], const int x_size[2], creal_T y_data[],
         int y_size[2]);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (fft.h) */
