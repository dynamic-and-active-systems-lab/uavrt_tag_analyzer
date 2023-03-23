/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * uavrt_tag_analyzer_rtwutil.h
 *
 * Code generation for function 'uavrt_tag_analyzer_rtwutil'
 *
 */

#ifndef UAVRT_TAG_ANALYZER_RTWUTIL_H
#define UAVRT_TAG_ANALYZER_RTWUTIL_H

/* Include files */
#include "rtwtypes.h"
#include "uavrt_tag_analyzer_types.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void c_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

extern int div_s32(int numerator, int denominator);

extern void emlrtDimSizeImpxCheckR2021b(const int aDim1, const int aDim2,
                                        const rtEqualityCheckInfo *aInfo);

extern void rtDivisionByZeroErrorN(void);

extern void rtDynamicBoundsError(int aIndexValue, int aLoBound, int aHiBound,
                                 const rtBoundsCheckInfo *aInfo);

extern void rtErrorWithMessageID(const char *aFcnName, int aLineNum);

extern void rtIntegerError(const double aInteger,
                           const rtDoubleCheckInfo *aInfo);

extern boolean_T rtIsNullOrEmptyString(const char *aString);

extern void rtNonNegativeError(const double aPositive,
                               const rtDoubleCheckInfo *aInfo);

extern void rtReportErrorLocation(const char *aFcnName, int aLineNo);

extern double rt_hypotd_snf(double u0, double u1);

extern double rt_roundd_snf(double u);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (uavrt_tag_analyzer_rtwutil.h) */
