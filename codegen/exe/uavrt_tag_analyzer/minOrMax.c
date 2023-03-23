/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * minOrMax.c
 *
 * Code generation for function 'minOrMax'
 *
 */

/* Include files */
#include "minOrMax.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "uavrt_tag_analyzer_internal_types.h"
#include "uavrt_tag_analyzer_rtwutil.h"
#include "uavrt_tag_analyzer_types.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <stdio.h>

/* Variable Definitions */
static rtRunTimeErrorInfo d_emlrtRTEI = {
    134,            /* lineNo */
    "unaryMinOrMax" /* fName */
};

/* Function Declarations */
static void o_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static double rt_atan2d_snf(double u0, double u1);

/* Function Definitions */
static void o_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  fprintf(stderr, "If the working dimension of MAX or MIN is variable in "
                  "length, it must not have zero length at runtime.");
  fprintf(stderr, "\n");
  fprintf(stderr, "Error in %s (line %d)", aFcnName, aLineNum);
  fprintf(stderr, "\n");
  fflush(stderr);
  abort();
}

static double rt_atan2d_snf(double u0, double u1)
{
  double y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = rtNaN;
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    int i;
    int i1;
    if (u0 > 0.0) {
      i = 1;
    } else {
      i = -1;
    }
    if (u1 > 0.0) {
      i1 = 1;
    } else {
      i1 = -1;
    }
    y = atan2(i, i1);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }
  return y;
}

double b_maximum(const emxArray_real_T *x)
{
  const double *x_data;
  double ex;
  int k;
  int last;
  x_data = x->data;
  if (x->size[0] < 1) {
    o_rtErrorWithMessageID(d_emlrtRTEI.fName, d_emlrtRTEI.lineNo);
  }
  last = x->size[0];
  if (x->size[0] <= 2) {
    if (x->size[0] == 1) {
      ex = x_data[0];
    } else if ((x_data[0] < x_data[1]) ||
               (rtIsNaN(x_data[0]) && (!rtIsNaN(x_data[1])))) {
      ex = x_data[1];
    } else {
      ex = x_data[0];
    }
  } else {
    int idx;
    if (!rtIsNaN(x_data[0])) {
      idx = 1;
    } else {
      boolean_T exitg1;
      idx = 0;
      if (x->size[0] > 2147483646) {
        check_forloop_overflow_error();
      }
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!rtIsNaN(x_data[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (idx == 0) {
      ex = x_data[0];
    } else {
      int a;
      ex = x_data[idx - 1];
      a = idx + 1;
      if ((idx + 1 <= x->size[0]) && (x->size[0] > 2147483646)) {
        check_forloop_overflow_error();
      }
      for (k = a; k <= last; k++) {
        double d;
        d = x_data[k - 1];
        if (ex < d) {
          ex = d;
        }
      }
    }
  }
  return ex;
}

int c_maximum(const emxArray_creal_T *x, creal_T *ex)
{
  const creal_T *x_data;
  int idx;
  int istop;
  int k;
  x_data = x->data;
  if (x->size[0] < 1) {
    o_rtErrorWithMessageID(d_emlrtRTEI.fName, d_emlrtRTEI.lineNo);
  }
  istop = x->size[0];
  idx = 1;
  *ex = x_data[0];
  if (x->size[0] > 2147483646) {
    check_forloop_overflow_error();
  }
  for (k = 2; k <= istop; k++) {
    creal_T dc;
    boolean_T SCALEA;
    dc = x_data[k - 1];
    if (rtIsNaN(dc.re) || rtIsNaN(x_data[k - 1].im)) {
      SCALEA = false;
    } else if (rtIsNaN(ex->re) || rtIsNaN(ex->im)) {
      SCALEA = true;
    } else {
      double b_x;
      double y;
      boolean_T SCALEB;
      if ((fabs(ex->re) > 8.9884656743115785E+307) ||
          (fabs(ex->im) > 8.9884656743115785E+307)) {
        SCALEA = true;
      } else {
        SCALEA = false;
      }
      if ((fabs(x_data[k - 1].re) > 8.9884656743115785E+307) ||
          (fabs(x_data[k - 1].im) > 8.9884656743115785E+307)) {
        SCALEB = true;
      } else {
        SCALEB = false;
      }
      if (SCALEA || SCALEB) {
        b_x = rt_hypotd_snf(ex->re / 2.0, ex->im / 2.0);
        y = rt_hypotd_snf(x_data[k - 1].re / 2.0, x_data[k - 1].im / 2.0);
      } else {
        b_x = rt_hypotd_snf(ex->re, ex->im);
        y = rt_hypotd_snf(x_data[k - 1].re, x_data[k - 1].im);
      }
      if (b_x == y) {
        double b_y_tmp;
        double y_tmp;
        b_x = rt_atan2d_snf(ex->im, ex->re);
        y_tmp = x_data[k - 1].re;
        b_y_tmp = x_data[k - 1].im;
        y = rt_atan2d_snf(b_y_tmp, y_tmp);
        if (b_x == y) {
          if (ex->re != y_tmp) {
            if (b_x >= 0.0) {
              b_x = y_tmp;
              b_y_tmp = ex->re;
            } else {
              b_x = ex->re;
              b_y_tmp = y_tmp;
            }
          } else if (ex->re < 0.0) {
            b_x = b_y_tmp;
            b_y_tmp = ex->im;
          } else {
            b_x = ex->im;
          }
          y = b_y_tmp;
          if (b_x == b_y_tmp) {
            b_x = 0.0;
            y = 0.0;
          }
        }
      }
      SCALEA = (b_x < y);
    }
    if (SCALEA) {
      *ex = dc;
      idx = k;
    }
  }
  return idx;
}

double maximum(const double x_data[], const int x_size[2])
{
  double ex;
  int k;
  int last;
  if (x_size[1] < 1) {
    o_rtErrorWithMessageID(d_emlrtRTEI.fName, d_emlrtRTEI.lineNo);
  }
  last = x_size[1];
  if (x_size[1] <= 2) {
    if (x_size[1] == 1) {
      ex = x_data[0];
    } else if ((x_data[0] < x_data[1]) ||
               (rtIsNaN(x_data[0]) && (!rtIsNaN(x_data[1])))) {
      ex = x_data[1];
    } else {
      ex = x_data[0];
    }
  } else {
    int idx;
    if (!rtIsNaN(x_data[0])) {
      idx = 1;
    } else {
      boolean_T exitg1;
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!rtIsNaN(x_data[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (idx == 0) {
      ex = x_data[0];
    } else {
      ex = x_data[idx - 1];
      idx++;
      for (k = idx; k <= last; k++) {
        double d;
        d = x_data[k - 1];
        if (ex < d) {
          ex = d;
        }
      }
    }
  }
  return ex;
}

/* End of code generation (minOrMax.c) */
