/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * fftshift.c
 *
 * Code generation for function 'fftshift'
 *
 */

/* Include files */
#include "fftshift.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "uavrt_tag_analyzer_types.h"

/* Function Definitions */
void fftshift(emxArray_creal_T *x)
{
  creal_T *x_data;
  int dim;
  int j;
  int k;
  x_data = x->data;
  for (dim = 0; dim < 2; dim++) {
    int a;
    int ic;
    ic = dim - 1;
    if (dim + 1 <= 1) {
      a = x->size[0];
    } else {
      a = 1;
    }
    if (a > 1) {
      int midoffset;
      int vlend2;
      int vstride;
      vlend2 = a / 2;
      vstride = 1;
      for (k = 0; k <= ic; k++) {
        vstride *= x->size[0];
      }
      midoffset = vlend2 * vstride - 1;
      if (vlend2 << 1 == a) {
        int i1;
        i1 = 0;
        if (vstride > 2147483646) {
          check_forloop_overflow_error();
        }
        for (j = 0; j < vstride; j++) {
          int ib;
          i1++;
          ib = i1 + midoffset;
          for (k = 0; k < vlend2; k++) {
            double xtmp_im;
            double xtmp_re;
            a = k * vstride;
            ic = (i1 + a) - 1;
            xtmp_re = x_data[ic].re;
            xtmp_im = x_data[ic].im;
            x_data[ic] = x_data[ib + a];
            a = ib + k * vstride;
            x_data[a].re = xtmp_re;
            x_data[a].im = xtmp_im;
          }
        }
      } else {
        int i1;
        i1 = 0;
        if (vstride > 2147483646) {
          check_forloop_overflow_error();
        }
        for (j = 0; j < vstride; j++) {
          double xtmp_im;
          double xtmp_re;
          int ib;
          i1++;
          ib = i1 + midoffset;
          xtmp_re = x_data[ib].re;
          xtmp_im = x_data[ib].im;
          for (k = 0; k < vlend2; k++) {
            ic = ib + vstride;
            a = (i1 + k * vstride) - 1;
            x_data[ib] = x_data[a];
            x_data[a] = x_data[ic];
            ib = ic;
          }
          x_data[ib].re = xtmp_re;
          x_data[ib].im = xtmp_im;
        }
      }
    }
  }
}

/* End of code generation (fftshift.c) */
