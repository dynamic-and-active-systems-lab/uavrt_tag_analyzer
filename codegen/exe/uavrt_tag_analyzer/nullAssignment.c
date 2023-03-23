/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * nullAssignment.c
 *
 * Code generation for function 'nullAssignment'
 *
 */

/* Include files */
#include "nullAssignment.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "uavrt_tag_analyzer_emxutil.h"
#include "uavrt_tag_analyzer_internal_types.h"
#include "uavrt_tag_analyzer_rtwutil.h"
#include "uavrt_tag_analyzer_types.h"
#include <stdio.h>

/* Variable Definitions */
static rtRunTimeErrorInfo j_emlrtRTEI = {
    85,               /* lineNo */
    "validate_inputs" /* fName */
};

/* Function Declarations */
static void p_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

/* Function Definitions */
static void p_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  fprintf(stderr, "Matrix index is out of range for deletion.");
  fprintf(stderr, "\n");
  fprintf(stderr, "Error in %s (line %d)", aFcnName, aLineNum);
  fprintf(stderr, "\n");
  fflush(stderr);
  abort();
}

void b_nullAssignment(emxArray_real_T *x, const emxArray_boolean_T *idx)
{
  static rtRunTimeErrorInfo k_emlrtRTEI = {
      184,                     /* lineNo */
      "onearg_null_assignment" /* fName */
  };
  double *x_data;
  int k;
  int k0;
  int nxin;
  int nxout;
  const boolean_T *idx_data;
  idx_data = idx->data;
  x_data = x->data;
  k = idx->size[1];
  while ((k >= 1) && (!idx_data[k - 1])) {
    k--;
  }
  if (k > x->size[1]) {
    p_rtErrorWithMessageID(j_emlrtRTEI.fName, j_emlrtRTEI.lineNo);
  }
  nxin = x->size[1];
  k0 = 0;
  nxout = idx->size[1];
  if (idx->size[1] > 2147483646) {
    check_forloop_overflow_error();
  }
  for (k = 0; k < nxout; k++) {
    k0 += idx_data[k];
  }
  nxout = x->size[1] - k0;
  k0 = -1;
  if (x->size[1] > 2147483646) {
    check_forloop_overflow_error();
  }
  for (k = 0; k < nxin; k++) {
    if ((k + 1 > idx->size[1]) || (!idx_data[k])) {
      k0++;
      x_data[k0] = x_data[k];
    }
  }
  if (nxout > x->size[1]) {
    rtErrorWithMessageID(k_emlrtRTEI.fName, k_emlrtRTEI.lineNo);
  }
  k0 = x->size[0] * x->size[1];
  if (nxout < 1) {
    x->size[1] = 0;
  } else {
    x->size[1] = nxout;
  }
  emxEnsureCapacity_real_T(x, k0);
}

void nullAssignment(emxArray_real_T *x, int idx)
{
  static rtRunTimeErrorInfo k_emlrtRTEI = {
      158,                     /* lineNo */
      "onearg_null_assignment" /* fName */
  };
  double *x_data;
  int k;
  int nxout;
  boolean_T p;
  x_data = x->data;
  p = true;
  if ((idx < 1) || (idx > x->size[0])) {
    p = false;
  }
  if (!p) {
    p_rtErrorWithMessageID(j_emlrtRTEI.fName, j_emlrtRTEI.lineNo);
  }
  nxout = x->size[0] - 1;
  for (k = idx; k <= nxout; k++) {
    x_data[k - 1] = x_data[k];
  }
  if (x->size[0] - 1 > x->size[0]) {
    rtErrorWithMessageID(k_emlrtRTEI.fName, k_emlrtRTEI.lineNo);
  }
  nxout = x->size[0];
  if (x->size[0] - 1 < 1) {
    x->size[0] = 0;
  } else {
    x->size[0]--;
  }
  emxEnsureCapacity_real_T(x, nxout);
}

/* End of code generation (nullAssignment.c) */
