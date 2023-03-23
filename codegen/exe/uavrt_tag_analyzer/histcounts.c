/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * histcounts.c
 *
 * Code generation for function 'histcounts'
 *
 */

/* Include files */
#include "histcounts.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "uavrt_tag_analyzer_internal_types.h"
#include "uavrt_tag_analyzer_types.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <stdio.h>
#include <string.h>

/* Function Declarations */
static double rt_powd_snf(double u0, double u1);

static void t_rtErrorWithMessageID(const char *r, const char *aFcnName,
                                   int aLineNum);

/* Function Definitions */
static double rt_powd_snf(double u0, double u1)
{
  double y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = rtNaN;
  } else {
    double d;
    double d1;
    d = fabs(u0);
    d1 = fabs(u1);
    if (rtIsInf(u1)) {
      if (d == 1.0) {
        y = 1.0;
      } else if (d > 1.0) {
        if (u1 > 0.0) {
          y = rtInf;
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = rtInf;
      }
    } else if (d1 == 0.0) {
      y = 1.0;
    } else if (d1 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = rtNaN;
    } else {
      y = pow(u0, u1);
    }
  }
  return y;
}

static void t_rtErrorWithMessageID(const char *r, const char *aFcnName,
                                   int aLineNum)
{
  fprintf(stderr,
          "Domain error. To compute complex results from real x, use "
          "\'%.*s(complex(x))\'.",
          5, r);
  fprintf(stderr, "\n");
  fprintf(stderr, "Error in %s (line %d)", aFcnName, aLineNum);
  fprintf(stderr, "\n");
  fflush(stderr);
  abort();
}

void histcounts(const emxArray_real_T *x, double n_data[], int n_size[2],
                double edges_data[], int edges_size[2])
{
  static rtRunTimeErrorInfo k_emlrtRTEI = {
      14,     /* lineNo */
      "log10" /* fName */
  };
  const double *x_data;
  double HighLimit;
  double LowLimit;
  double absx;
  double binWidth;
  double leftEdge;
  int ni_data[10];
  int high_i;
  int k;
  int low_i;
  int low_ip1;
  int mid_i;
  int nx;
  x_data = x->data;
  nx = x->size[0];
  k = 0;
  while ((k + 1 <= nx) && (rtIsInf(x_data[k]) || rtIsNaN(x_data[k]))) {
    k++;
  }
  if (k + 1 > x->size[0]) {
    LowLimit = 0.0;
    low_i = 0;
  } else {
    LowLimit = x_data[k];
    low_i = 1;
  }
  HighLimit = LowLimit;
  low_ip1 = k + 2;
  if ((k + 2 <= x->size[0]) && (x->size[0] > 2147483646)) {
    check_forloop_overflow_error();
  }
  for (mid_i = low_ip1; mid_i <= nx; mid_i++) {
    absx = x_data[mid_i - 1];
    if ((!rtIsInf(absx)) && (!rtIsNaN(absx))) {
      if (absx < LowLimit) {
        LowLimit = absx;
      } else if (absx > HighLimit) {
        HighLimit = absx;
      }
      low_i++;
    }
  }
  if (low_i > 0) {
    absx = fmax(fabs(LowLimit), fabs(HighLimit));
    if (rtIsInf(absx) || rtIsNaN(absx)) {
      absx = rtNaN;
    } else if (absx < 4.4501477170144028E-308) {
      absx = 4.94065645841247E-324;
    } else {
      frexp(absx, &high_i);
      absx = ldexp(1.0, high_i - 53);
    }
    binWidth = HighLimit - LowLimit;
    leftEdge = fmax(binWidth / 10.0, absx);
    if (binWidth > fmax(sqrt(absx), 2.2250738585072014E-308)) {
      if (leftEdge < 0.0) {
        t_rtErrorWithMessageID("log10", k_emlrtRTEI.fName, k_emlrtRTEI.lineNo);
      }
      absx = rt_powd_snf(10.0, floor(log10(leftEdge)));
      binWidth = absx * floor(leftEdge / absx);
      leftEdge = fmax(fmin(binWidth * floor(LowLimit / binWidth), LowLimit),
                      -1.7976931348623157E+308);
      absx = HighLimit - leftEdge;
      binWidth = absx / 10.0;
      absx = absx / 9.0 - binWidth;
      if (absx < 0.0) {
        t_rtErrorWithMessageID("log10", k_emlrtRTEI.fName, k_emlrtRTEI.lineNo);
      }
      absx = rt_powd_snf(10.0, floor(log10(absx)));
      binWidth = absx * ceil(binWidth / absx);
      absx = fmin(fmax(leftEdge + 10.0 * binWidth, HighLimit),
                  1.7976931348623157E+308);
    } else {
      absx = fmax(1.0, ceil(10.0 * absx));
      leftEdge = floor(2.0 * (LowLimit - absx / 4.0)) / 2.0;
      absx = ceil(2.0 * (HighLimit + absx / 4.0)) / 2.0;
      binWidth = (absx - leftEdge) / 10.0;
    }
    if ((!rtIsInf(binWidth)) && (!rtIsNaN(binWidth))) {
      edges_size[0] = 1;
      edges_size[1] = 11;
      memset(&edges_data[0], 0, 11U * sizeof(double));
      edges_data[0] = leftEdge;
      for (low_i = 0; low_i < 9; low_i++) {
        edges_data[low_i + 1] = leftEdge + ((double)low_i + 1.0) * binWidth;
      }
      edges_data[10] = absx;
    } else {
      edges_size[0] = 1;
      edges_size[1] = 11;
      edges_data[10] = absx;
      edges_data[0] = leftEdge;
      if (leftEdge == -absx) {
        absx /= 10.0;
        for (k = 0; k < 9; k++) {
          edges_data[k + 1] = (2.0 * ((double)k + 2.0) - 12.0) * absx;
        }
        edges_data[5] = 0.0;
      } else if (((leftEdge < 0.0) != (absx < 0.0)) &&
                 ((fabs(leftEdge) > 8.9884656743115785E+307) ||
                  (fabs(absx) > 8.9884656743115785E+307))) {
        binWidth = leftEdge / 10.0;
        absx /= 10.0;
        for (k = 0; k < 9; k++) {
          edges_data[k + 1] = (leftEdge + absx * ((double)k + 1.0)) -
                              binWidth * ((double)k + 1.0);
        }
      } else {
        binWidth = (absx - leftEdge) / 10.0;
        for (k = 0; k < 9; k++) {
          edges_data[k + 1] = leftEdge + ((double)k + 1.0) * binWidth;
        }
      }
    }
  } else {
    edges_size[0] = 1;
    edges_size[1] = 11;
    for (k = 0; k < 11; k++) {
      edges_data[k] = k;
    }
  }
  for (low_i = 0; low_i < 10; low_i++) {
    ni_data[low_i] = 0;
  }
  nx = x->size[0];
  leftEdge = edges_data[0];
  absx = edges_data[1] - edges_data[0];
  for (k = 0; k < nx; k++) {
    if ((x_data[k] >= leftEdge) && (x_data[k] <= edges_data[10])) {
      boolean_T guard1 = false;
      binWidth = ceil((x_data[k] - leftEdge) / absx);
      guard1 = false;
      if ((binWidth >= 1.0) && (binWidth < 11.0)) {
        low_i = (int)binWidth;
        if ((x_data[k] >= edges_data[low_i - 1]) &&
            (x_data[k] < edges_data[low_i])) {
          ni_data[low_i - 1]++;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
      if (guard1) {
        low_i = 1;
        low_ip1 = 2;
        high_i = 11;
        while (high_i > low_ip1) {
          mid_i = (low_i >> 1) + (high_i >> 1);
          if (((low_i & 1) == 1) && ((high_i & 1) == 1)) {
            mid_i++;
          }
          if (x_data[k] >= edges_data[mid_i - 1]) {
            low_i = mid_i;
            low_ip1 = mid_i + 1;
          } else {
            high_i = mid_i;
          }
        }
        ni_data[low_i - 1]++;
      }
    }
  }
  n_size[0] = 1;
  n_size[1] = 10;
  for (low_i = 0; low_i < 10; low_i++) {
    n_data[low_i] = ni_data[low_i];
  }
}

/* End of code generation (histcounts.c) */
