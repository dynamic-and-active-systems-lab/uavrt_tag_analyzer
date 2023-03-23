/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * eml_int_forloop_overflow_check.c
 *
 * Code generation for function 'eml_int_forloop_overflow_check'
 *
 */

/* Include files */
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "uavrt_tag_analyzer_internal_types.h"
#include <stdio.h>

/* Function Declarations */
static void v_rtErrorWithMessageID(const char *r, const char *aFcnName,
                                   int aLineNum);

/* Function Definitions */
static void v_rtErrorWithMessageID(const char *r, const char *aFcnName,
                                   int aLineNum)
{
  fprintf(stderr,
          "The loop variable of class %.*s might overflow on the last "
          "iteration of the for loop. This could lead to an infinite loop.",
          5, r);
  fprintf(stderr, "\n");
  fprintf(stderr, "Error in %s (line %d)", aFcnName, aLineNum);
  fprintf(stderr, "\n");
  fflush(stderr);
  abort();
}

void check_forloop_overflow_error(void)
{
  static rtRunTimeErrorInfo k_emlrtRTEI = {
      87,                            /* lineNo */
      "check_forloop_overflow_error" /* fName */
  };
  v_rtErrorWithMessageID("int32", k_emlrtRTEI.fName, k_emlrtRTEI.lineNo);
}

/* End of code generation (eml_int_forloop_overflow_check.c) */
