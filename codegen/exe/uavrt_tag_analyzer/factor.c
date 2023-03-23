/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * factor.c
 *
 * Code generation for function 'factor'
 *
 */

/* Include files */
#include "factor.h"
#include "eml_primes_core.h"
#include "rt_nonfinite.h"
#include "uavrt_tag_analyzer_internal_types.h"
#include "uavrt_tag_analyzer_rtwutil.h"
#include "uavrt_tag_analyzer_types.h"
#include <stdio.h>

/* Function Declarations */
static void b_rtReportErrorLocation(const char *aFcnName, int aLineNo);

static void rtDivisionByZeroError(const rtRunTimeErrorInfo *aInfo);

/* Function Definitions */
static void b_rtReportErrorLocation(const char *aFcnName, int aLineNo)
{
  fprintf(stderr, "Error in %s (line %d)", aFcnName, aLineNo);
  fprintf(stderr, "\n");
}

static void rtDivisionByZeroError(const rtRunTimeErrorInfo *aInfo)
{
  fprintf(
      stderr,
      "Division by zero detected.\nEarly termination due to division by zero.");
  fprintf(stderr, "\n");
  b_rtReportErrorLocation(aInfo->fName, aInfo->lineNo);
  fflush(stderr);
  abort();
}

void factor(unsigned int n, unsigned int fctrs_data[], int fctrs_size[2])
{
  static rtDoubleCheckInfo b_emlrtDCI = {
      105,         /* lineNo */
      "eml_primes" /* fName */
  };
  static rtRunTimeErrorInfo k_emlrtRTEI = {
      241,        /* lineNo */
      "intdivide" /* fName */
  };
  static rtRunTimeErrorInfo l_emlrtRTEI = {
      174,         /* lineNo */
      "eml_factor" /* fName */
  };
  static rtRunTimeErrorInfo m_emlrtRTEI = {
      103,         /* lineNo */
      "eml_primes" /* fName */
  };
  unsigned int b_n;
  int i;
  int j;
  int k;
  b_n = n;
  fctrs_size[0] = 1;
  if (n < 4U) {
    fctrs_size[0] = 1;
    fctrs_size[1] = 1;
    fctrs_data[0] = n;
  } else {
    int p_data[6542];
    unsigned int ifctrsnew;
    int kmax;
    unsigned int nf;
    int nleft;
    unsigned int sqrtn;
    boolean_T exitg1;
    sqrtn = intsqrt(n);
    if (sqrtn > 2147483647U) {
      sqrtn = 2147483647U;
    }
    if ((int)sqrtn < 2) {
      nleft = 0;
    } else if ((int)sqrtn < 3) {
      nleft = 1;
      p_data[0] = 2;
    } else {
      int np_tmp;
      boolean_T isp_data[32768];
      ifctrsnew = sqrtn >> 1;
      if (sqrtn - (ifctrsnew << 1) > 0U) {
        ifctrsnew++;
      }
      np_tmp = (int)ifctrsnew;
      for (i = 0; i < np_tmp; i++) {
        isp_data[i] = true;
      }
      kmax = b_intsqrt((int)sqrtn);
      k = 3;
      nleft = (int)ifctrsnew;
      while (k <= kmax) {
        if (isp_data[(k + 1) / 2 - 1]) {
          i = (k * k + 1) / 2;
          for (j = i; k < 0 ? j >= np_tmp : j <= np_tmp; j += k) {
            if (isp_data[j - 1]) {
              isp_data[j - 1] = false;
              nleft--;
            }
          }
        }
        k += 2;
      }
      kmax = (int)ifctrsnew;
      if (kmax > 6542) {
        kmax = 6542;
      }
      if (nleft > kmax) {
        rtErrorWithMessageID(m_emlrtRTEI.fName, m_emlrtRTEI.lineNo);
      }
      if (nleft < 0) {
        rtNonNegativeError(nleft, &b_emlrtDCI);
      }
      kmax = 1;
      p_data[0] = 2;
      for (k = 2; k <= np_tmp; k++) {
        if (isp_data[k - 1] && (kmax < 6542)) {
          kmax++;
          p_data[kmax - 1] = (k << 1) - 1;
        }
      }
    }
    nf = 0U;
    exitg1 = false;
    while ((!exitg1) && (b_n > 1U)) {
      unsigned int prodp;
      kmax = 0;
      prodp = 1U;
      for (k = 0; k < nleft; k++) {
        i = p_data[k];
        if (i < 0) {
          i = 0;
        }
        if ((unsigned int)i == 0U) {
          sqrtn = 0U;
        } else {
          sqrtn = b_n % (unsigned int)i;
        }
        if ((int)sqrtn == 0) {
          kmax = (int)((unsigned int)kmax + 1U);
          p_data[kmax - 1] = p_data[k];
          prodp *= (unsigned int)i;
        }
      }
      if (kmax == 0) {
        nf++;
        fctrs_data[(int)nf - 1] = b_n;
        exitg1 = true;
      } else {
        nleft = kmax;
        sqrtn = nf;
        nf += (unsigned int)kmax;
        ifctrsnew = nf;
        while (kmax > 0) {
          boolean_T guard1 = false;
          guard1 = false;
          if (sqrtn < 1U) {
            guard1 = true;
          } else {
            unsigned int u;
            u = fctrs_data[(int)sqrtn - 1];
            if ((int)u < p_data[kmax - 1]) {
              guard1 = true;
            } else {
              fctrs_data[(int)ifctrsnew - 1] = u;
              sqrtn--;
            }
          }
          if (guard1) {
            i = p_data[kmax - 1];
            if (i < 0) {
              i = 0;
            }
            fctrs_data[(int)ifctrsnew - 1] = (unsigned int)i;
            kmax = (int)((unsigned int)kmax - 1U);
          }
          ifctrsnew--;
        }
        if (prodp == 0U) {
          rtDivisionByZeroError(&k_emlrtRTEI);
        } else {
          b_n /= prodp;
        }
      }
    }
    if (nf > 31U) {
      rtErrorWithMessageID(l_emlrtRTEI.fName, l_emlrtRTEI.lineNo);
    }
    if (nf < 1U) {
      fctrs_size[1] = 0;
    } else {
      fctrs_size[1] = (int)nf;
    }
  }
}

/* End of code generation (factor.c) */
