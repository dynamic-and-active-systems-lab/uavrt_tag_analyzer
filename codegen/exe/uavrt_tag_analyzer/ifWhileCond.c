/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * ifWhileCond.c
 *
 * Code generation for function 'ifWhileCond'
 *
 */

/* Include files */
#include "ifWhileCond.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "uavrt_tag_analyzer_types.h"

/* Function Definitions */
boolean_T ifWhileCond(const emxArray_boolean_T *x)
{
  const boolean_T *x_data;
  boolean_T y;
  x_data = x->data;
  y = (x->size[0] != 0);
  if (y) {
    int k;
    boolean_T exitg1;
    if (x->size[0] > 2147483646) {
      check_forloop_overflow_error();
    }
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= x->size[0] - 1)) {
      if (!x_data[k]) {
        y = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  return y;
}

/* End of code generation (ifWhileCond.c) */
