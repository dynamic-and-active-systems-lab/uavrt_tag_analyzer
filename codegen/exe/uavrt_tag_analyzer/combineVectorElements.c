/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * combineVectorElements.c
 *
 * Code generation for function 'combineVectorElements'
 *
 */

/* Include files */
#include "combineVectorElements.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "uavrt_tag_analyzer_emxutil.h"
#include "uavrt_tag_analyzer_types.h"

/* Function Definitions */
void combineVectorElements(const emxArray_boolean_T *x, emxArray_int32_T *y)
{
  int i;
  int *y_data;
  const boolean_T *x_data;
  x_data = x->data;
  if (x->size[1] == 0) {
    y->size[0] = 1;
    y->size[1] = 0;
  } else {
    int npages;
    npages = x->size[1];
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = x->size[1];
    emxEnsureCapacity_int32_T(y, i);
    y_data = y->data;
    if (x->size[1] > 2147483646) {
      check_forloop_overflow_error();
    }
    for (i = 0; i < npages; i++) {
      y_data[i] = x_data[i];
    }
  }
}

/* End of code generation (combineVectorElements.c) */
