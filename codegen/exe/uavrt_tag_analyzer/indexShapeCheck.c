/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * indexShapeCheck.c
 *
 * Code generation for function 'indexShapeCheck'
 *
 */

/* Include files */
#include "indexShapeCheck.h"
#include "rt_nonfinite.h"
#include "uavrt_tag_analyzer_internal_types.h"
#include <stdio.h>

/* Variable Definitions */
static rtRunTimeErrorInfo b_emlrtRTEI = {
    122,          /* lineNo */
    "errOrWarnIf" /* fName */
};

/* Function Declarations */
static void h_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

/* Function Definitions */
static void h_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  fprintf(stderr,
          "Compile-time size assumption violated. At run-time, a vector "
          "indexes a scalar, but the compile-time assumption is that the vecto"
          "r is indexed by a vector of the same size.");
  fprintf(stderr, "\n");
  fprintf(stderr, "Error in %s (line %d)", aFcnName, aLineNum);
  fprintf(stderr, "\n");
  fflush(stderr);
  abort();
}

void b_indexShapeCheck(int matrixSize)
{
  if (matrixSize == 1) {
    h_rtErrorWithMessageID(b_emlrtRTEI.fName, b_emlrtRTEI.lineNo);
  }
}

void indexShapeCheck(int matrixSize, const int indexSize[2])
{
  if ((matrixSize == 1) && (indexSize[1] != 1)) {
    h_rtErrorWithMessageID(b_emlrtRTEI.fName, b_emlrtRTEI.lineNo);
  }
}

/* End of code generation (indexShapeCheck.c) */
