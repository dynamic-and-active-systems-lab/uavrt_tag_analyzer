/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * uavrt_tag_analyzer_rtwutil.c
 *
 * Code generation for function 'uavrt_tag_analyzer_rtwutil'
 *
 */

/* Include files */
#include "uavrt_tag_analyzer_rtwutil.h"
#include "rt_nonfinite.h"
#include "uavrt_tag_analyzer_types.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <stdio.h>

/* Function Definitions */
void c_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  fprintf(stderr,
          "The dimension to operate along was selected automatically, is "
          "variable-length, and has length 1 at run time. This is not support"
          "ed. Manually select the dimension to operate along by supplying the "
          "DIM argument.");
  fprintf(stderr, "\n");
  fprintf(stderr, "Error in %s (line %d)", aFcnName, aLineNum);
  fprintf(stderr, "\n");
  fflush(stderr);
  abort();
}

int div_s32(int numerator, int denominator)
{
  int quotient;
  if (denominator == 0) {
    rtDivisionByZeroErrorN();
  } else {
    unsigned int tempAbsQuotient;
    unsigned int u;
    if (numerator < 0) {
      tempAbsQuotient = ~(unsigned int)numerator + 1U;
    } else {
      tempAbsQuotient = (unsigned int)numerator;
    }
    if (denominator < 0) {
      u = ~(unsigned int)denominator + 1U;
    } else {
      u = (unsigned int)denominator;
    }
    tempAbsQuotient /= u;
    if ((numerator < 0) != (denominator < 0)) {
      quotient = -(int)tempAbsQuotient;
    } else {
      quotient = (int)tempAbsQuotient;
    }
  }
  return quotient;
}

void emlrtDimSizeImpxCheckR2021b(const int aDim1, const int aDim2,
                                 const rtEqualityCheckInfo *aInfo)
{
  fprintf(stderr,
          "Size mismatch error on dimension %d: expected %d or a singleton, "
          "but actual size is %d.",
          aInfo->nDims, aDim1, aDim2);
  fprintf(stderr, "\n");
  rtReportErrorLocation(aInfo->fName, aInfo->lineNo);
  fflush(stderr);
  abort();
}

void rtDivisionByZeroErrorN(void)
{
  fprintf(
      stderr,
      "Division by zero detected.\nEarly termination due to division by zero.");
  fprintf(stderr, "\n");
  fflush(stderr);
  abort();
}

void rtDynamicBoundsError(int aIndexValue, int aLoBound, int aHiBound,
                          const rtBoundsCheckInfo *aInfo)
{
  if (aLoBound == 0) {
    aIndexValue++;
    aLoBound = 1;
    aHiBound++;
  }
  if (rtIsNullOrEmptyString(aInfo->aName)) {
    fprintf(stderr,
            "Index exceeds array dimensions. Index value %d exceeds valid "
            "range [%d-%d].",
            aIndexValue, aLoBound, aHiBound);
    fprintf(stderr, "\n");
    rtReportErrorLocation(aInfo->fName, aInfo->lineNo);
    fflush(stderr);
    abort();
  } else {
    fprintf(stderr,
            "Index exceeds array dimensions. Index value %d exceeds valid "
            "range [%d-%d] for array \'%s\'.",
            aIndexValue, aLoBound, aHiBound, aInfo->aName);
    fprintf(stderr, "\n");
    rtReportErrorLocation(aInfo->fName, aInfo->lineNo);
    fflush(stderr);
    abort();
  }
}

void rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  fprintf(stderr, "Assertion failed.");
  fprintf(stderr, "\n");
  fprintf(stderr, "Error in %s (line %d)", aFcnName, aLineNum);
  fprintf(stderr, "\n");
  fflush(stderr);
  abort();
}

void rtIntegerError(const double aInteger, const rtDoubleCheckInfo *aInfo)
{
  fprintf(
      stderr,
      "Expected a value representable in the C type \'int\'. Found %g instead.",
      aInteger);
  fprintf(stderr, "\n");
  rtReportErrorLocation(aInfo->fName, aInfo->lineNo);
  fflush(stderr);
  abort();
}

boolean_T rtIsNullOrEmptyString(const char *aString)
{
  return (aString == NULL) || (*aString == '\x00');
}

void rtNonNegativeError(const double aPositive, const rtDoubleCheckInfo *aInfo)
{
  fprintf(stderr,
          "Value %g is not greater than or equal to zero.\nExiting to prevent "
          "memory corruption.",
          aPositive);
  fprintf(stderr, "\n");
  rtReportErrorLocation(aInfo->fName, aInfo->lineNo);
  fflush(stderr);
  abort();
}

void rtReportErrorLocation(const char *aFcnName, int aLineNo)
{
  fprintf(stderr, "Error in %s (line %d)", aFcnName, aLineNo);
  fprintf(stderr, "\n");
}

double rt_hypotd_snf(double u0, double u1)
{
  double a;
  double b;
  double y;
  a = fabs(u0);
  b = fabs(u1);
  if (a < b) {
    a /= b;
    y = b * sqrt(a * a + 1.0);
  } else if (a > b) {
    b /= a;
    y = a * sqrt(b * b + 1.0);
  } else if (rtIsNaN(b)) {
    y = rtNaN;
  } else {
    y = a * 1.4142135623730951;
  }
  return y;
}

double rt_roundd_snf(double u)
{
  double y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }
  return y;
}

/* End of code generation (uavrt_tag_analyzer_rtwutil.c) */
