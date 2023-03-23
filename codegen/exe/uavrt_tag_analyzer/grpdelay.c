/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * grpdelay.c
 *
 * Code generation for function 'grpdelay'
 *
 */

/* Include files */
#include "grpdelay.h"
#include "div.h"
#include "fft.h"
#include "find.h"
#include "islinphase.h"
#include "minOrMax.h"
#include "rt_nonfinite.h"
#include "uavrt_tag_analyzer_data.h"
#include "uavrt_tag_analyzer_emxutil.h"
#include "uavrt_tag_analyzer_internal_types.h"
#include "uavrt_tag_analyzer_rtwutil.h"
#include "uavrt_tag_analyzer_types.h"
#include <math.h>
#include <stdio.h>
#include <string.h>

/* Function Declarations */
static void l_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

/* Function Definitions */
static void l_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  fprintf(stderr, "Arrays have incompatible sizes for this operation.");
  fprintf(stderr, "\n");
  fprintf(stderr, "Error in %s (line %d)", aFcnName, aLineNum);
  fprintf(stderr, "\n");
  fflush(stderr);
  abort();
}

void grpdelay(const double b[31], double gd_out[8])
{
  static rtBoundsCheckInfo b_emlrtBCI = {
      -1,         /* iFirst */
      -1,         /* iLast */
      248,        /* lineNo */
      25,         /* colNo */
      "",         /* aName */
      "smithDly", /* fName */
      "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/grpdelay.m", /* pName
                                                                           */
      0 /* checkKind */
  };
  static rtBoundsCheckInfo c_emlrtBCI = {
      -1,         /* iFirst */
      -1,         /* iLast */
      248,        /* lineNo */
      36,         /* colNo */
      "",         /* aName */
      "smithDly", /* fName */
      "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/grpdelay.m", /* pName
                                                                           */
      0 /* checkKind */
  };
  static rtBoundsCheckInfo d_emlrtBCI = {
      -1,         /* iFirst */
      -1,         /* iLast */
      248,        /* lineNo */
      16,         /* colNo */
      "",         /* aName */
      "smithDly", /* fName */
      "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/grpdelay.m", /* pName
                                                                           */
      0 /* checkKind */
  };
  static rtBoundsCheckInfo e_emlrtBCI = {
      -1,         /* iFirst */
      -1,         /* iLast */
      248,        /* lineNo */
      28,         /* colNo */
      "",         /* aName */
      "smithDly", /* fName */
      "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/grpdelay.m", /* pName
                                                                           */
      0 /* checkKind */
  };
  static rtBoundsCheckInfo emlrtBCI = {
      -1,         /* iFirst */
      -1,         /* iLast */
      219,        /* lineNo */
      24,         /* colNo */
      "",         /* aName */
      "smithDly", /* fName */
      "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/grpdelay.m", /* pName
                                                                           */
      0 /* checkKind */
  };
  static rtBoundsCheckInfo f_emlrtBCI = {
      -1,         /* iFirst */
      -1,         /* iLast */
      225,        /* lineNo */
      24,         /* colNo */
      "",         /* aName */
      "smithDly", /* fName */
      "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/grpdelay.m", /* pName
                                                                           */
      0 /* checkKind */
  };
  static rtBoundsCheckInfo g_emlrtBCI = {
      -1,         /* iFirst */
      -1,         /* iLast */
      225,        /* lineNo */
      32,         /* colNo */
      "",         /* aName */
      "smithDly", /* fName */
      "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/grpdelay.m", /* pName
                                                                           */
      0 /* checkKind */
  };
  static rtEqualityCheckInfo emlrtECI = {
      2,          /* nDims */
      225,        /* lineNo */
      15,         /* colNo */
      "smithDly", /* fName */
      "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/grpdelay.m" /* pName
                                                                          */
  };
  static rtRunTimeErrorInfo k_emlrtRTEI = {
      79,        /* lineNo */
      "convFull" /* fName */
  };
  static rtRunTimeErrorInfo l_emlrtRTEI = {
      13,                    /* lineNo */
      "assertCompatibleDims" /* fName */
  };
  static const signed char iv[31] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0};
  emxArray_real_T *y;
  creal_T den_data[77];
  creal_T gd1_data[77];
  creal_T tmp_data[64];
  double b_cr_data[77];
  double c_data[62];
  double cr_data[62];
  double a_data[31];
  double b_data[31];
  double G;
  double *y_data;
  int a_size[2];
  int b_size[2];
  int cr_size[2];
  int den_size[2];
  int gd1_size[2];
  int tmp_size[2];
  int b_ii_data;
  int i;
  int idx;
  int k;
  int n;
  int nApnB;
  int nfact;
  signed char ii_data;
  boolean_T exitg1;
  idx = 0;
  nfact = 31;
  exitg1 = false;
  while ((!exitg1) && (nfact > 0)) {
    if (b[nfact - 1] != 0.0) {
      idx = 1;
      ii_data = (signed char)nfact;
      exitg1 = true;
    } else {
      nfact--;
    }
  }
  if (idx == 0) {
    n = 1;
  } else {
    n = ii_data;
  }
  a_size[0] = 1;
  a_size[1] = n;
  b_size[0] = 1;
  b_size[1] = n;
  for (i = 0; i < n; i++) {
    a_data[i] = iv[i];
    b_data[i] = b[i];
  }
  idx = n - 1;
  nApnB = (n + n) - 1;
  if (nApnB > nApnB + 1) {
    rtErrorWithMessageID(k_emlrtRTEI.fName, k_emlrtRTEI.lineNo);
  }
  memset(&c_data[0], 0, (unsigned int)nApnB * sizeof(double));
  for (k = 0; k <= idx; k++) {
    for (b_ii_data = 0; b_ii_data <= idx; b_ii_data++) {
      nfact = k + b_ii_data;
      c_data[nfact] += a_data[(n - k) - 1] * b[b_ii_data];
    }
  }
  cr_size[0] = 1;
  cr_size[1] = nApnB;
  for (i = 0; i < nApnB; i++) {
    cr_data[i] = c_data[i] * (double)i;
  }
  if (nApnB <= 16) {
    tmp_size[0] = 1;
    tmp_size[1] = 16;
    memcpy(&b_cr_data[0], &cr_data[0], (unsigned int)nApnB * sizeof(double));
    idx = 16 - nApnB;
    if (idx - 1 >= 0) {
      memset(&b_cr_data[nApnB], 0,
             (unsigned int)((idx + nApnB) - nApnB) * sizeof(double));
    }
    fft(b_cr_data, tmp_size, gd1_data, gd1_size);
    tmp_size[0] = 1;
    tmp_size[1] = 16;
    memcpy(&b_cr_data[0], &c_data[0], (unsigned int)nApnB * sizeof(double));
    if (idx - 1 >= 0) {
      memset(&b_cr_data[nApnB], 0,
             (unsigned int)((idx + nApnB) - nApnB) * sizeof(double));
    }
    fft(b_cr_data, tmp_size, den_data, den_size);
    if ((gd1_size[1] != 1) && (den_size[1] != 1) &&
        (gd1_size[1] != den_size[1])) {
      l_rtErrorWithMessageID(l_emlrtRTEI.fName, l_emlrtRTEI.lineNo);
    }
    if (gd1_size[1] == den_size[1]) {
      k = gd1_size[1] - 1;
      for (i = 0; i <= k; i++) {
        double ai;
        double ar;
        double bi;
        double br;
        double re;
        ar = gd1_data[i].re;
        ai = gd1_data[i].im;
        br = den_data[i].re;
        bi = den_data[i].im;
        if (bi == 0.0) {
          if (ai == 0.0) {
            re = ar / br;
            G = 0.0;
          } else if (ar == 0.0) {
            re = 0.0;
            G = ai / br;
          } else {
            re = ar / br;
            G = ai / br;
          }
        } else if (br == 0.0) {
          if (ar == 0.0) {
            re = ai / bi;
            G = 0.0;
          } else if (ai == 0.0) {
            re = 0.0;
            G = -(ar / bi);
          } else {
            re = ai / bi;
            G = -(ar / bi);
          }
        } else {
          double brm;
          brm = fabs(br);
          G = fabs(bi);
          if (brm > G) {
            double s;
            s = bi / br;
            G = br + s * bi;
            re = (ar + s * ai) / G;
            G = (ai - s * ar) / G;
          } else if (G == brm) {
            double s;
            if (br > 0.0) {
              s = 0.5;
            } else {
              s = -0.5;
            }
            if (bi > 0.0) {
              G = 0.5;
            } else {
              G = -0.5;
            }
            re = (ar * s + ai * G) / brm;
            G = (ai * s - ar * G) / brm;
          } else {
            double s;
            s = br / bi;
            G = bi + s * br;
            re = (s * ar + ai) / G;
            G = (s * ai - ar) / G;
          }
        }
        gd1_data[i].re = re;
        gd1_data[i].im = G;
      }
    } else {
      rdivide(gd1_data, gd1_size, den_data, den_size);
    }
    i = gd1_size[1];
    for (idx = 0; idx < 8; idx++) {
      if (idx + 1 > i) {
        rtDynamicBoundsError(idx + 1, 1, i, &emlrtBCI);
      }
      gd_out[idx] = gd1_data[idx].re - ((double)n - 1.0);
    }
  } else {
    double b_tmp_data[16];
    nfact = (int)ceil((double)nApnB / 16.0) << 1;
    idx = nfact << 3;
    b_fft(cr_data, cr_size, idx, tmp_data, tmp_size);
    gd1_size[0] = 1;
    gd1_size[1] = tmp_size[1];
    k = tmp_size[1];
    if (k - 1 >= 0) {
      memcpy(&gd1_data[0], &tmp_data[0], (unsigned int)k * sizeof(creal_T));
    }
    cr_size[0] = 1;
    cr_size[1] = nApnB;
    memcpy(&cr_data[0], &c_data[0], (unsigned int)nApnB * sizeof(double));
    b_fft(cr_data, cr_size, idx, tmp_data, tmp_size);
    den_size[0] = 1;
    den_size[1] = tmp_size[1];
    k = tmp_size[1];
    if (k - 1 >= 0) {
      memcpy(&den_data[0], &tmp_data[0], (unsigned int)k * sizeof(creal_T));
    }
    if ((gd1_size[1] != 1) && (tmp_size[1] != 1) &&
        (gd1_size[1] != tmp_size[1])) {
      l_rtErrorWithMessageID(l_emlrtRTEI.fName, l_emlrtRTEI.lineNo);
    }
    if (gd1_size[1] == tmp_size[1]) {
      k = gd1_size[1] - 1;
      for (i = 0; i <= k; i++) {
        double ai;
        double ar;
        double bi;
        double br;
        double re;
        ar = gd1_data[i].re;
        ai = gd1_data[i].im;
        br = den_data[i].re;
        bi = den_data[i].im;
        if (bi == 0.0) {
          if (ai == 0.0) {
            re = ar / br;
            G = 0.0;
          } else if (ar == 0.0) {
            re = 0.0;
            G = ai / br;
          } else {
            re = ar / br;
            G = ai / br;
          }
        } else if (br == 0.0) {
          if (ar == 0.0) {
            re = ai / bi;
            G = 0.0;
          } else if (ai == 0.0) {
            re = 0.0;
            G = -(ar / bi);
          } else {
            re = ai / bi;
            G = -(ar / bi);
          }
        } else {
          double brm;
          brm = fabs(br);
          G = fabs(bi);
          if (brm > G) {
            double s;
            s = bi / br;
            G = br + s * bi;
            re = (ar + s * ai) / G;
            G = (ai - s * ar) / G;
          } else if (G == brm) {
            double s;
            if (br > 0.0) {
              s = 0.5;
            } else {
              s = -0.5;
            }
            if (bi > 0.0) {
              G = 0.5;
            } else {
              G = -0.5;
            }
            re = (ar * s + ai * G) / brm;
            G = (ai * s - ar * G) / brm;
          } else {
            double s;
            s = br / bi;
            G = bi + s * br;
            re = (s * ar + ai) / G;
            G = (s * ai - ar) / G;
          }
        }
        gd1_data[i].re = re;
        gd1_data[i].im = G;
      }
    } else {
      rdivide(gd1_data, gd1_size, den_data, den_size);
    }
    if (gd1_size[1] < 1) {
      rtDynamicBoundsError(1, 1, gd1_size[1], &f_emlrtBCI);
    }
    if (idx > gd1_size[1]) {
      rtDynamicBoundsError(idx, 1, gd1_size[1], &g_emlrtBCI);
    }
    k = div_s32(idx - 1, nfact);
    idx = k + 1;
    for (i = 0; i <= k; i++) {
      b_tmp_data[i] = gd1_data[nfact * i].re;
    }
    if ((k + 1 != 8) && (k + 1 != 1)) {
      emlrtDimSizeImpxCheckR2021b(k + 1, 8, &emlrtECI);
    }
    for (i = 0; i < idx; i++) {
      gd_out[i] = b_tmp_data[i] - ((double)n - 1.0);
    }
  }
  if (islinphase(b_data, b_size, a_data, a_size)) {
    int startidx_size_idx_1;
    eml_find(b_data, b_size, (int *)&b_ii_data, tmp_size);
    startidx_size_idx_1 = tmp_size[1];
    k = tmp_size[1];
    for (i = 0; i < k; i++) {
      nApnB = b_ii_data;
    }
    nfact = n;
    idx = 0;
    tmp_size[1] = 1;
    exitg1 = false;
    while ((!exitg1) && (nfact > 0)) {
      if (b[nfact - 1] != 0.0) {
        idx = 1;
        b_ii_data = nfact;
        exitg1 = true;
      } else {
        nfact--;
      }
    }
    if (idx == 0) {
      tmp_size[1] = 0;
    }
    k = tmp_size[1];
    for (i = 0; i < k; i++) {
      ii_data = (signed char)b_ii_data;
    }
    emxInit_real_T(&y, 2);
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = n;
    emxEnsureCapacity_real_T(y, i);
    y_data = y->data;
    for (k = 0; k < n; k++) {
      y_data[k] = fabs(b[k]);
    }
    a_size[0] = (*(int(*)[2])y->size)[0];
    a_size[1] = (*(int(*)[2])y->size)[1];
    G = maximum((double *)y->data, a_size);
    emxFree_real_T(&y);
    if (G == 0.0) {
      ii_data = 1;
    } else {
      if (startidx_size_idx_1 < 1) {
        rtDynamicBoundsError(1, 1, startidx_size_idx_1, &b_emlrtBCI);
      }
      if (tmp_size[1] < 1) {
        rtDynamicBoundsError(1, 1, 0, &c_emlrtBCI);
      }
      if (nApnB > ii_data) {
        i = 1;
        idx = 0;
      } else {
        if ((nApnB < 1) || (nApnB > n)) {
          rtDynamicBoundsError(nApnB, 1, n, &d_emlrtBCI);
        }
        i = nApnB;
        if (ii_data > n) {
          rtDynamicBoundsError(ii_data, 1, n, &e_emlrtBCI);
        }
        idx = ii_data;
      }
      ii_data = (signed char)((idx - i) + 1);
    }
    if (startidx_size_idx_1 == 0) {
      idx = 0;
    } else {
      idx = (int)fmax((double)nApnB - 1.0, 0.0);
    }
    G = (double)idx + ((double)ii_data - 1.0) / 2.0;
    for (idx = 0; idx < 8; idx++) {
      gd_out[idx] = G;
    }
  }
}

/* End of code generation (grpdelay.c) */
