/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * FFTImplementationCallback.h
 *
 * Code generation for function 'FFTImplementationCallback'
 *
 */

#ifndef FFTIMPLEMENTATIONCALLBACK_H
#define FFTIMPLEMENTATIONCALLBACK_H

/* Include files */
#include "rtwtypes.h"
#include "uavrt_tag_analyzer_types.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
int c_FFTImplementationCallback_dob(
    const double x_data[], int x_size, int n2blue, int nfft,
    const double costab_data[], const int costab_size[2],
    const double sintab_data[], const int sintab_size[2],
    const double sintabinv_data[], const int sintabinv_size[2],
    creal_T y_data[]);

void c_FFTImplementationCallback_gen(int nRows, boolean_T useRadix2,
                                     double costab_data[], int costab_size[2],
                                     double sintab_data[], int sintab_size[2],
                                     double sintabinv_data[],
                                     int sintabinv_size[2]);

int c_FFTImplementationCallback_get(int nfft, boolean_T useRadix2, int *nRows);

int c_FFTImplementationCallback_r2b(const double x_data[], int x_size,
                                    int n1_unsigned, const double costab_data[],
                                    const int costab_size[2],
                                    const double sintab_data[],
                                    creal_T y_data[]);

void d_FFTImplementationCallback_r2b(const emxArray_creal_T *x,
                                     int unsigned_nRows,
                                     const emxArray_real_T *costab,
                                     const emxArray_real_T *sintab,
                                     emxArray_creal_T *y);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (FFTImplementationCallback.h) */
