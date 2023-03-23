/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * std.c
 *
 * Code generation for function 'std'
 *
 */

/* Include files */
#include "std.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "uavrt_tag_analyzer_types.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
double b_std(const emxArray_real_T *x)
{
  const double *x_data;
  double y;
  int ib;
  int k;
  int n;
  x_data = x->data;
  n = x->size[1];
  if (x->size[1] == 0) {
    y = rtNaN;
  } else if (x->size[1] == 1) {
    if ((!rtIsInf(x_data[0])) && (!rtIsNaN(x_data[0]))) {
      y = 0.0;
    } else {
      y = rtNaN;
    }
  } else {
    double bsum;
    double xbar;
    int firstBlockLength;
    int lastBlockLength;
    int nblocks;
    if (x->size[1] <= 1024) {
      firstBlockLength = x->size[1];
      lastBlockLength = 0;
      nblocks = 1;
    } else {
      firstBlockLength = 1024;
      nblocks = (int)((unsigned int)x->size[1] >> 10);
      lastBlockLength = x->size[1] - (nblocks << 10);
      if (lastBlockLength > 0) {
        nblocks++;
      } else {
        lastBlockLength = 1024;
      }
    }
    xbar = x_data[0];
    for (k = 2; k <= firstBlockLength; k++) {
      xbar += x_data[k - 1];
    }
    for (ib = 2; ib <= nblocks; ib++) {
      int hi;
      firstBlockLength = (ib - 1) << 10;
      bsum = x_data[firstBlockLength];
      if (ib == nblocks) {
        hi = lastBlockLength;
      } else {
        hi = 1024;
      }
      for (k = 2; k <= hi; k++) {
        bsum += x_data[(firstBlockLength + k) - 1];
      }
      xbar += bsum;
    }
    xbar /= (double)x->size[1];
    if (x->size[1] > 2147483646) {
      check_forloop_overflow_error();
    }
    y = 0.0;
    bsum = 3.3121686421112381E-170;
    for (k = 0; k < n; k++) {
      double d;
      d = fabs(x_data[k] - xbar);
      if (d > bsum) {
        double t;
        t = bsum / d;
        y = y * t * t + 1.0;
        bsum = d;
      } else {
        double t;
        t = d / bsum;
        y += t * t;
      }
    }
    y = bsum * sqrt(y);
    y /= sqrt((double)x->size[1] - 1.0);
  }
  return y;
}

/* End of code generation (std.c) */
