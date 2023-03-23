/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * locateoutliers.c
 *
 * Code generation for function 'locateoutliers'
 *
 */

/* Include files */
#include "locateoutliers.h"
#include "eml_int_forloop_overflow_check.h"
#include "median.h"
#include "rt_nonfinite.h"
#include "uavrt_tag_analyzer_emxutil.h"
#include "uavrt_tag_analyzer_types.h"
#include <math.h>

/* Function Definitions */
void locateoutliers(const emxArray_real_T *a, emxArray_boolean_T *tf)
{
  emxArray_real_T *x;
  emxArray_real_T *y;
  const double *a_data;
  double amad;
  double center;
  double lb;
  double *x_data;
  double *y_data;
  int k;
  int nx;
  boolean_T *tf_data;
  a_data = a->data;
  center = median(a);
  emxInit_real_T(&x, 2);
  k = x->size[0] * x->size[1];
  x->size[0] = 1;
  x->size[1] = a->size[1];
  emxEnsureCapacity_real_T(x, k);
  x_data = x->data;
  nx = a->size[1];
  for (k = 0; k < nx; k++) {
    x_data[k] = a_data[k] - center;
  }
  nx = x->size[1];
  emxInit_real_T(&y, 2);
  k = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = x->size[1];
  emxEnsureCapacity_real_T(y, k);
  y_data = y->data;
  if (x->size[1] > 2147483646) {
    check_forloop_overflow_error();
  }
  for (k = 0; k < nx; k++) {
    y_data[k] = fabs(x_data[k]);
  }
  emxFree_real_T(&x);
  amad = 1.4826022185056018 * median(y);
  emxFree_real_T(&y);
  lb = center - 3.0 * amad;
  center += 3.0 * amad;
  k = tf->size[0] * tf->size[1];
  tf->size[0] = 1;
  tf->size[1] = a->size[1];
  emxEnsureCapacity_boolean_T(tf, k);
  tf_data = tf->data;
  nx = a->size[1];
  for (k = 0; k < nx; k++) {
    amad = a_data[k];
    tf_data[k] = ((amad < lb) || (amad > center));
  }
}

/* End of code generation (locateoutliers.c) */
