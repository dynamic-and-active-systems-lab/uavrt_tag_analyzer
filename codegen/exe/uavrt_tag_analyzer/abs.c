/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * abs.c
 *
 * Code generation for function 'abs'
 *
 */

/* Include files */
#include "abs.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "uavrt_tag_analyzer_emxutil.h"
#include "uavrt_tag_analyzer_rtwutil.h"
#include "uavrt_tag_analyzer_types.h"

/* Function Definitions */
void b_abs(const emxArray_creal_T *x, emxArray_real_T *y)
{
  const creal_T *x_data;
  double *y_data;
  int k;
  int nx;
  x_data = x->data;
  nx = x->size[0];
  k = y->size[0];
  y->size[0] = x->size[0];
  emxEnsureCapacity_real_T(y, k);
  y_data = y->data;
  if (x->size[0] > 2147483646) {
    check_forloop_overflow_error();
  }
  for (k = 0; k < nx; k++) {
    y_data[k] = rt_hypotd_snf(x_data[k].re, x_data[k].im);
  }
}

/* End of code generation (abs.c) */
