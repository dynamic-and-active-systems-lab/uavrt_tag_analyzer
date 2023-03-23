/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * decimate.c
 *
 * Code generation for function 'decimate'
 *
 */

/* Include files */
#include "decimate.h"
#include "eml_int_forloop_overflow_check.h"
#include "firls.h"
#include "grpdelay.h"
#include "indexShapeCheck.h"
#include "rt_nonfinite.h"
#include "uavrt_tag_analyzer_emxutil.h"
#include "uavrt_tag_analyzer_internal_types.h"
#include "uavrt_tag_analyzer_rtwutil.h"
#include "uavrt_tag_analyzer_types.h"
#include <math.h>
#include <stdio.h>
#include <string.h>

/* Function Declarations */
static void q_rtErrorWithMessageID(const char *r, const char *aFcnName,
                                   int aLineNum);

static void r_rtErrorWithMessageID(const char *r, const char *aFcnName,
                                   int aLineNum);

/* Function Definitions */
static void q_rtErrorWithMessageID(const char *r, const char *aFcnName,
                                   int aLineNum)
{
  fprintf(stderr, "The input signal %.*s must be a double-precision vector.", 1,
          r);
  fprintf(stderr, "\n");
  fprintf(stderr, "Error in %s (line %d)", aFcnName, aLineNum);
  fprintf(stderr, "\n");
  fflush(stderr);
  abort();
}

static void r_rtErrorWithMessageID(const char *r, const char *aFcnName,
                                   int aLineNum)
{
  fprintf(stderr, "Resampling rate %.*s must be a positive integer.", 1, r);
  fprintf(stderr, "\n");
  fprintf(stderr, "Error in %s (line %d)", aFcnName, aLineNum);
  fprintf(stderr, "\n");
  fflush(stderr);
  abort();
}

void decimate(const emxArray_creal_T *idata, unsigned int r,
              emxArray_creal_T *y)
{
  static rtBoundsCheckInfo b_emlrtBCI = {
      -1,         /* iFirst */
      -1,         /* iLast */
      101,        /* lineNo */
      34,         /* colNo */
      "",         /* aName */
      "decimate", /* fName */
      "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/decimate.m", /* pName
                                                                           */
      0 /* checkKind */
  };
  static rtBoundsCheckInfo c_emlrtBCI = {
      -1,         /* iFirst */
      -1,         /* iLast */
      131,        /* lineNo */
      15,         /* colNo */
      "",         /* aName */
      "decimate", /* fName */
      "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/decimate.m", /* pName
                                                                           */
      0 /* checkKind */
  };
  static rtBoundsCheckInfo d_emlrtBCI = {
      -1,         /* iFirst */
      -1,         /* iLast */
      131,        /* lineNo */
      26,         /* colNo */
      "",         /* aName */
      "decimate", /* fName */
      "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/decimate.m", /* pName
                                                                           */
      0 /* checkKind */
  };
  static rtBoundsCheckInfo e_emlrtBCI = {
      -1,         /* iFirst */
      -1,         /* iLast */
      136,        /* lineNo */
      15,         /* colNo */
      "",         /* aName */
      "decimate", /* fName */
      "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/decimate.m", /* pName
                                                                           */
      0 /* checkKind */
  };
  static rtBoundsCheckInfo emlrtBCI = {
      -1,         /* iFirst */
      -1,         /* iLast */
      93,         /* lineNo */
      36,         /* colNo */
      "",         /* aName */
      "decimate", /* fName */
      "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/decimate.m", /* pName
                                                                           */
      0 /* checkKind */
  };
  static rtBoundsCheckInfo f_emlrtBCI = {
      1,          /* iFirst */
      62,         /* iLast */
      136,        /* lineNo */
      26,         /* colNo */
      "",         /* aName */
      "decimate", /* fName */
      "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/decimate.m", /* pName
                                                                           */
      0 /* checkKind */
  };
  static rtRunTimeErrorInfo k_emlrtRTEI = {
      176,            /* lineNo */
      "validateinput" /* fName */
  };
  static rtRunTimeErrorInfo l_emlrtRTEI = {
      178,            /* lineNo */
      "validateinput" /* fName */
  };
  static rtRunTimeErrorInfo m_emlrtRTEI = {
      124,       /* lineNo */
      "decimate" /* fName */
  };
  static const double wind[31] = {0.080000000000000016, 0.090052103662449423,
                                  0.11976908948440362,  0.16785218258752421,
                                  0.23219992107492521,  0.30999999999999994,
                                  0.39785218258752419,  0.49191690689687945,
                                  0.58808309310312057,  0.68214781741247577,
                                  0.76999999999999991,  0.8478000789250747,
                                  0.91214781741247575,  0.9602309105155965,
                                  0.98994789633755065,  1.0,
                                  0.98994789633755065,  0.9602309105155965,
                                  0.91214781741247575,  0.8478000789250747,
                                  0.76999999999999991,  0.68214781741247577,
                                  0.58808309310312057,  0.49191690689687945,
                                  0.39785218258752419,  0.30999999999999994,
                                  0.23219992107492521,  0.16785218258752421,
                                  0.11976908948440362,  0.090052103662449423,
                                  0.080000000000000016};
  emxArray_creal_T *odata;
  creal_T itemp[62];
  creal_T zf[30];
  creal_T zi[30];
  const creal_T *idata_data;
  creal_T *odata_data;
  creal_T *y_data;
  double hh_data[31];
  int i;
  int j;
  int k;
  int naxpy;
  idata_data = idata->data;
  if (idata->size[0] == 0) {
    q_rtErrorWithMessageID("X", k_emlrtRTEI.fName, k_emlrtRTEI.lineNo);
  }
  if (r <= 0U) {
    r_rtErrorWithMessageID("R", l_emlrtRTEI.fName, l_emlrtRTEI.lineNo);
  }
  if (r == 1U) {
    int niccp;
    i = y->size[0];
    y->size[0] = idata->size[0];
    emxEnsureCapacity_creal_T(y, i);
    y_data = y->data;
    niccp = idata->size[0];
    for (i = 0; i < niccp; i++) {
      y_data[i] = idata_data[i];
    }
  } else {
    creal_T x[62];
    creal_T initItemp[31];
    double b[31];
    double dv[4];
    double Wn;
    double y_im;
    int hh_size[2];
    int boffset_tmp;
    int niccp;
    int nout;
    int nx;
    boolean_T b_b;
    nout = (int)ceil((double)idata->size[0] / (double)r);
    Wn = 1.0 / (double)r;
    dv[0] = 0.0;
    dv[1] = Wn;
    dv[2] = Wn;
    dv[3] = 1.0;
    firls(dv, hh_data, hh_size);
    for (i = 0; i < 31; i++) {
      b[i] = hh_data[i] * wind[i];
    }
    Wn = b[0];
    for (k = 0; k < 30; k++) {
      Wn += b[k + 1];
    }
    for (i = 0; i < 31; i++) {
      b[i] /= Wn;
    }
    b_indexShapeCheck(idata->size[0]);
    Wn = 2.0 * idata_data[0].re;
    y_im = 2.0 * idata_data[0].im;
    for (i = 0; i < 31; i++) {
      if (32 - i > idata->size[0]) {
        rtDynamicBoundsError(32 - i, 1, idata->size[0], &emlrtBCI);
      }
      initItemp[i].re = Wn - idata_data[31 - i].re;
      if (32 - i > idata->size[0]) {
        rtDynamicBoundsError(32 - i, 1, idata->size[0], &emlrtBCI);
      }
      initItemp[i].im = y_im - idata_data[31 - i].im;
    }
    memset(&zi[0], 0, 30U * sizeof(creal_T));
    for (k = 0; k < 30; k++) {
      for (j = 0; j <= k; j++) {
        Wn = b[(j - k) + 30];
        zi[j].re += initItemp[k + 1].re * Wn;
        zi[j].im += initItemp[k + 1].im * Wn;
      }
    }
    emxInit_creal_T(&odata);
    i = odata->size[0];
    odata->size[0] = idata->size[0];
    emxEnsureCapacity_creal_T(odata, i);
    odata_data = odata->data;
    nx = idata->size[0];
    memset(&zf[0], 0, 30U * sizeof(creal_T));
    if (idata->size[0] < 30) {
      niccp = idata->size[0] + 1;
    } else {
      niccp = 31;
    }
    for (k = 0; k <= niccp - 2; k++) {
      odata_data[k] = zi[k];
    }
    if ((niccp <= idata->size[0]) && (idata->size[0] > 2147483646)) {
      check_forloop_overflow_error();
    }
    for (k = niccp; k <= nx; k++) {
      odata_data[k - 1].re = 0.0;
      odata_data[k - 1].im = 0.0;
    }
    if (idata->size[0] >= 62) {
      for (k = 0; k < 31; k++) {
        niccp = k + 1;
        if (nx > 2147483646) {
          check_forloop_overflow_error();
        }
        Wn = b[k];
        for (j = niccp; j <= nx; j++) {
          i = (j - k) - 1;
          odata_data[j - 1].re += Wn * idata_data[i].re;
          odata_data[j - 1].im += Wn * idata_data[i].im;
        }
      }
    } else {
      if (idata->size[0] > 31) {
        niccp = idata->size[0] - 32;
      } else {
        niccp = -1;
      }
      for (k = 0; k <= niccp; k++) {
        for (j = 0; j < 31; j++) {
          i = k + j;
          Wn = b[j];
          odata_data[i].re += idata_data[k].re * Wn;
          odata_data[i].im += idata_data[k].im * Wn;
        }
      }
      naxpy = (idata->size[0] - niccp) - 1;
      i = niccp + 2;
      for (k = i; k <= nx; k++) {
        if (naxpy > 2147483646) {
          check_forloop_overflow_error();
        }
        for (j = 0; j < naxpy; j++) {
          niccp = (k + j) - 1;
          Wn = b[j];
          odata_data[niccp].re += idata_data[k - 1].re * Wn;
          odata_data[niccp].im += idata_data[k - 1].im * Wn;
        }
        naxpy--;
      }
    }
    if (idata->size[0] < 30) {
      i = 29 - idata->size[0];
      for (k = 0; k <= i; k++) {
        zf[k] = zi[k + nx];
      }
    }
    if (idata->size[0] >= 31) {
      niccp = idata->size[0] - 30;
    } else {
      niccp = 0;
    }
    i = idata->size[0] - 1;
    for (k = niccp; k <= i; k++) {
      boffset_tmp = nx - k;
      naxpy = 31 - boffset_tmp;
      if (31 - boffset_tmp > 2147483646) {
        check_forloop_overflow_error();
      }
      for (j = 0; j < naxpy; j++) {
        Wn = b[boffset_tmp + j];
        zf[j].re += idata_data[k].re * Wn;
        zf[j].im += idata_data[k].im * Wn;
      }
    }
    b_indexShapeCheck(idata->size[0]);
    Wn = 2.0 * idata_data[idata->size[0] - 1].re;
    y_im = 2.0 * idata_data[idata->size[0] - 1].im;
    for (i = 0; i < 62; i++) {
      niccp = (idata->size[0] - i) - 1;
      b_b = ((niccp < 1) || (niccp > idata->size[0]));
      if (b_b) {
        rtDynamicBoundsError(niccp, 1, idata->size[0], &b_emlrtBCI);
      }
      x[i].re = Wn - idata_data[niccp - 1].re;
      x[i].im = y_im - idata_data[niccp - 1].im;
    }
    memcpy(&itemp[0], &zf[0], 30U * sizeof(creal_T));
    memset(&itemp[30], 0, 32U * sizeof(creal_T));
    for (k = 0; k < 31; k++) {
      niccp = k + 1;
      Wn = b[k];
      for (j = niccp; j < 63; j++) {
        i = (j - k) - 1;
        itemp[j - 1].re += Wn * x[i].re;
        itemp[j - 1].im += Wn * x[i].im;
      }
    }
    double gd[8];
    grpdelay(b, gd);
    Wn = rt_roundd_snf(gd[0] + 1.25);
    niccp = div_s32(idata->size[0] - (int)Wn, (int)r);
    if (nout > idata->size[0]) {
      rtErrorWithMessageID(m_emlrtRTEI.fName, m_emlrtRTEI.lineNo);
    }
    i = y->size[0];
    y->size[0] = nout;
    emxEnsureCapacity_creal_T(y, i);
    y_data = y->data;
    if (niccp + 1 > 2147483646) {
      check_forloop_overflow_error();
    }
    for (naxpy = 0; naxpy <= niccp; naxpy++) {
      b_b = ((naxpy + 1 < 1) || (naxpy + 1 > y->size[0]));
      if (b_b) {
        rtDynamicBoundsError(naxpy + 1, 1, y->size[0], &c_emlrtBCI);
      }
      i = (int)Wn + naxpy * (int)r;
      b_b = ((i < 1) || (i > odata->size[0]));
      if (b_b) {
        rtDynamicBoundsError(i, 1, odata->size[0], &d_emlrtBCI);
      }
      y_data[naxpy].re = odata_data[i - 1].re;
      y_data[naxpy].im = odata_data[i - 1].im;
    }
    emxFree_creal_T(&odata);
    k = (((int)r - idata->size[0]) + (int)Wn) + niccp * (int)r;
    boffset_tmp = niccp + 2;
    for (naxpy = boffset_tmp; naxpy <= nout; naxpy++) {
      if ((naxpy < 1) || (naxpy > y->size[0])) {
        rtDynamicBoundsError(naxpy, 1, y->size[0], &e_emlrtBCI);
      }
      i = k + ((naxpy - niccp) - 2) * (int)r;
      if ((i < 1) || (i > 62)) {
        rtDynamicBoundsError(i, 1, 62, &f_emlrtBCI);
      }
      y_data[naxpy - 1].re = itemp[i - 1].re;
      if (naxpy > y->size[0]) {
        rtDynamicBoundsError(naxpy, 1, y->size[0], &e_emlrtBCI);
      }
      y_data[naxpy - 1].im = itemp[i - 1].im;
    }
  }
}

/* End of code generation (decimate.c) */
