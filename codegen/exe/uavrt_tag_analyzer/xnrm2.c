/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * xnrm2.c
 *
 * Code generation for function 'xnrm2'
 *
 */

/* Include files */
#include "xnrm2.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
double xnrm2(int n, const double x_data[], int ix0)
{
  double y;
  int k;
  y = 0.0;
  if (n == 1) {
    y = fabs(x_data[ix0 - 1]);
  } else {
    double scale;
    int kend;
    scale = 3.3121686421112381E-170;
    kend = (ix0 + n) - 1;
    if ((ix0 <= kend) && (kend > 2147483646)) {
      check_forloop_overflow_error();
    }
    for (k = ix0; k <= kend; k++) {
      double absxk;
      absxk = fabs(x_data[k - 1]);
      if (absxk > scale) {
        double t;
        t = scale / absxk;
        y = y * t * t + 1.0;
        scale = absxk;
      } else {
        double t;
        t = absxk / scale;
        y += t * t;
      }
    }
    y = scale * sqrt(y);
  }
  return y;
}

/* End of code generation (xnrm2.c) */
