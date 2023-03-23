/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * eml_primes_core.c
 *
 * Code generation for function 'eml_primes_core'
 *
 */

/* Include files */
#include "eml_primes_core.h"
#include "rt_nonfinite.h"
#include "uavrt_tag_analyzer_internal_types.h"
#include "uavrt_tag_analyzer_rtwutil.h"

/* Variable Definitions */
static rtRunTimeErrorInfo c_emlrtRTEI = {
    330,      /* lineNo */
    "intsqrt" /* fName */
};

/* Function Definitions */
int b_intsqrt(int a)
{
  int r;
  int rhi;
  rhi = a / 2 + 1;
  if (a >= rhi * rhi) {
    r = rhi;
  } else {
    int rlo;
    boolean_T exitg1;
    rlo = 0;
    r = rhi / 2;
    exitg1 = false;
    while ((!exitg1) && (r > rlo)) {
      int rr;
      rr = r * r;
      if (rr == a) {
        exitg1 = true;
      } else {
        if (rr > a) {
          rhi = r;
        } else {
          rlo = r;
        }
        rr = (rhi - rlo) / 2;
        if ((rlo > 0) && (rr > MAX_int32_T - rlo)) {
          r = MAX_int32_T;
        } else {
          r = rlo + rr;
        }
      }
    }
  }
  if (r > 46340) {
    rtErrorWithMessageID(c_emlrtRTEI.fName, c_emlrtRTEI.lineNo);
  }
  return r;
}

unsigned int intsqrt(unsigned int a)
{
  unsigned int r;
  unsigned int rhi;
  rhi = (a >> 1) + 1U;
  if (rhi >= 65535U) {
    rhi = 65535U;
  }
  if (a >= rhi * rhi) {
    r = rhi;
  } else {
    unsigned int rlo;
    boolean_T exitg1;
    rlo = 0U;
    r = rhi >> 1;
    exitg1 = false;
    while ((!exitg1) && (r > rlo)) {
      unsigned int rr;
      rr = r * r;
      if (rr == a) {
        exitg1 = true;
      } else {
        if (rr > a) {
          rhi = r;
        } else {
          rlo = r;
        }
        r = rlo + ((rhi - rlo) >> 1);
        if (r < rlo) {
          r = MAX_uint32_T;
        }
      }
    }
  }
  if (r > 65535U) {
    rtErrorWithMessageID(c_emlrtRTEI.fName, c_emlrtRTEI.lineNo);
  }
  return r;
}

/* End of code generation (eml_primes_core.c) */
