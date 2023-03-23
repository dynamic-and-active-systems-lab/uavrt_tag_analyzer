/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * median.c
 *
 * Code generation for function 'median'
 *
 */

/* Include files */
#include "median.h"
#include "eml_int_forloop_overflow_check.h"
#include "quickselect.h"
#include "rt_nonfinite.h"
#include "uavrt_tag_analyzer_emxutil.h"
#include "uavrt_tag_analyzer_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
double median(const emxArray_real_T *x)
{
  emxArray_real_T *b_x;
  const double *x_data;
  double y;
  double *b_x_data;
  int b_vlen;
  int loop_ub;
  int vlen;
  x_data = x->data;
  vlen = x->size[1];
  if (x->size[1] == 0) {
    y = rtNaN;
  } else {
    emxInit_real_T(&b_x, 2);
    b_vlen = b_x->size[0] * b_x->size[1];
    b_x->size[0] = 1;
    b_x->size[1] = x->size[1];
    emxEnsureCapacity_real_T(b_x, b_vlen);
    b_x_data = b_x->data;
    loop_ub = x->size[1];
    for (b_vlen = 0; b_vlen < loop_ub; b_vlen++) {
      b_x_data[b_vlen] = x_data[b_vlen];
    }
    b_vlen = 0;
    if (x->size[1] > 2147483646) {
      check_forloop_overflow_error();
    }
    for (loop_ub = 0; loop_ub < vlen; loop_ub++) {
      if (!rtIsNaN(b_x_data[loop_ub])) {
        b_vlen++;
        if (b_vlen < loop_ub + 1) {
          b_x_data[b_vlen - 1] = b_x_data[loop_ub];
        }
      }
    }
    if (b_vlen <= 4) {
      if (b_vlen == 0) {
        y = rtNaN;
      } else if (b_vlen == 1) {
        y = b_x_data[0];
      } else if (b_vlen == 2) {
        if (((b_x_data[0] < 0.0) != (b_x_data[1] < 0.0)) ||
            rtIsInf(b_x_data[0])) {
          y = (b_x_data[0] + b_x_data[1]) / 2.0;
        } else {
          y = b_x_data[0] + (b_x_data[1] - b_x_data[0]) / 2.0;
        }
      } else if (b_vlen == 3) {
        if (b_x_data[0] < b_x_data[1]) {
          if (b_x_data[1] < b_x_data[2]) {
            vlen = 1;
          } else if (b_x_data[0] < b_x_data[2]) {
            vlen = 2;
          } else {
            vlen = 0;
          }
        } else if (b_x_data[0] < b_x_data[2]) {
          vlen = 0;
        } else if (b_x_data[1] < b_x_data[2]) {
          vlen = 2;
        } else {
          vlen = 1;
        }
        y = b_x_data[vlen];
      } else {
        if (b_x_data[0] < b_x_data[1]) {
          if (b_x_data[1] < b_x_data[2]) {
            loop_ub = 0;
            vlen = 1;
            b_vlen = 2;
          } else if (b_x_data[0] < b_x_data[2]) {
            loop_ub = 0;
            vlen = 2;
            b_vlen = 1;
          } else {
            loop_ub = 2;
            vlen = 0;
            b_vlen = 1;
          }
        } else if (b_x_data[0] < b_x_data[2]) {
          loop_ub = 1;
          vlen = 0;
          b_vlen = 2;
        } else if (b_x_data[1] < b_x_data[2]) {
          loop_ub = 1;
          vlen = 2;
          b_vlen = 0;
        } else {
          loop_ub = 2;
          vlen = 1;
          b_vlen = 0;
        }
        if (b_x_data[loop_ub] < b_x_data[3]) {
          if (b_x_data[3] < b_x_data[b_vlen]) {
            if (((b_x_data[vlen] < 0.0) != (b_x_data[3] < 0.0)) ||
                rtIsInf(b_x_data[vlen])) {
              y = (b_x_data[vlen] + b_x_data[3]) / 2.0;
            } else {
              y = b_x_data[vlen] + (b_x_data[3] - b_x_data[vlen]) / 2.0;
            }
          } else if (((b_x_data[vlen] < 0.0) != (b_x_data[b_vlen] < 0.0)) ||
                     rtIsInf(b_x_data[vlen])) {
            y = (b_x_data[vlen] + b_x_data[b_vlen]) / 2.0;
          } else {
            y = b_x_data[vlen] + (b_x_data[b_vlen] - b_x_data[vlen]) / 2.0;
          }
        } else if (((b_x_data[loop_ub] < 0.0) != (b_x_data[vlen] < 0.0)) ||
                   rtIsInf(b_x_data[loop_ub])) {
          y = (b_x_data[loop_ub] + b_x_data[vlen]) / 2.0;
        } else {
          y = b_x_data[loop_ub] + (b_x_data[vlen] - b_x_data[loop_ub]) / 2.0;
        }
      }
    } else {
      int midm1;
      midm1 = b_vlen >> 1;
      if ((b_vlen & 1) == 0) {
        y = quickselect(b_x, midm1 + 1, b_vlen, &loop_ub, &vlen);
        if (midm1 < loop_ub) {
          double b;
          b = quickselect(b_x, midm1, vlen - 1, &loop_ub, &b_vlen);
          if (((y < 0.0) != (b < 0.0)) || rtIsInf(y)) {
            y = (y + b) / 2.0;
          } else {
            y += (b - y) / 2.0;
          }
        }
      } else {
        y = quickselect(b_x, midm1 + 1, b_vlen, &loop_ub, &vlen);
      }
    }
    emxFree_real_T(&b_x);
  }
  return y;
}

/* End of code generation (median.c) */
