/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * diff.c
 *
 * Code generation for function 'diff'
 *
 */

/* Include files */
#include "diff.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "uavrt_tag_analyzer_emxutil.h"
#include "uavrt_tag_analyzer_internal_types.h"
#include "uavrt_tag_analyzer_rtwutil.h"
#include "uavrt_tag_analyzer_types.h"

/* Variable Definitions */
static rtRunTimeErrorInfo f_emlrtRTEI = {
    51,    /* lineNo */
    "diff" /* fName */
};

/* Function Definitions */
void b_diff(const emxArray_real_T *x, emxArray_real_T *y)
{
  const double *x_data;
  double *y_data;
  int dimSize;
  int u0;
  x_data = x->data;
  dimSize = x->size[1];
  if (x->size[1] == 0) {
    y->size[0] = 1;
    y->size[1] = 0;
  } else {
    u0 = x->size[1] - 1;
    if (u0 > 1) {
      u0 = 1;
    }
    if (u0 < 1) {
      y->size[0] = 1;
      y->size[1] = 0;
    } else {
      double work_data;
      if (x->size[1] == 1) {
        c_rtErrorWithMessageID(f_emlrtRTEI.fName, f_emlrtRTEI.lineNo);
      }
      u0 = y->size[0] * y->size[1];
      y->size[0] = 1;
      y->size[1] = x->size[1] - 1;
      emxEnsureCapacity_real_T(y, u0);
      y_data = y->data;
      work_data = x_data[0];
      if (x->size[1] > 2147483646) {
        check_forloop_overflow_error();
      }
      for (u0 = 2; u0 <= dimSize; u0++) {
        double d;
        double tmp1;
        tmp1 = x_data[u0 - 1];
        d = tmp1;
        tmp1 -= work_data;
        work_data = d;
        y_data[u0 - 2] = tmp1;
      }
    }
  }
}

void diff(const emxArray_real_T *x, emxArray_real_T *y)
{
  const double *x_data;
  double *y_data;
  int dimSize;
  int u0;
  x_data = x->data;
  dimSize = x->size[0];
  if (x->size[0] == 0) {
    y->size[0] = 0;
  } else {
    u0 = x->size[0] - 1;
    if (u0 > 1) {
      u0 = 1;
    }
    if (u0 < 1) {
      y->size[0] = 0;
    } else {
      double work_data;
      if (x->size[0] == 1) {
        c_rtErrorWithMessageID(f_emlrtRTEI.fName, f_emlrtRTEI.lineNo);
      }
      u0 = y->size[0];
      y->size[0] = x->size[0] - 1;
      emxEnsureCapacity_real_T(y, u0);
      y_data = y->data;
      work_data = x_data[0];
      if (x->size[0] > 2147483646) {
        check_forloop_overflow_error();
      }
      for (u0 = 2; u0 <= dimSize; u0++) {
        double tmp2;
        tmp2 = work_data;
        work_data = x_data[u0 - 1];
        y_data[u0 - 2] = work_data - tmp2;
      }
    }
  }
}

/* End of code generation (diff.c) */
