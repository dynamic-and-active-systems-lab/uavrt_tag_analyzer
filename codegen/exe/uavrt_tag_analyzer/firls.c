/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * firls.c
 *
 * Code generation for function 'firls'
 *
 */

/* Include files */
#include "firls.h"
#include "eml_mtimes_helper.h"
#include "indexShapeCheck.h"
#include "mldivide.h"
#include "rt_nonfinite.h"
#include "uavrt_tag_analyzer_internal_types.h"
#include "uavrt_tag_analyzer_rtwutil.h"
#include "uavrt_tag_analyzer_types.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <stdio.h>
#include <string.h>

/* Function Declarations */
static void i_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void j_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void minus(double in1_data[], int in1_size[2], const double in2_data[],
                  const int in2_size[2]);

static void plus(double in1_data[], int in1_size[2], const double in2_data[],
                 const int in2_size[2]);

static void s_rtErrorWithMessageID(const char *r, const char *aFcnName,
                                   int aLineNum);

/* Function Definitions */
static void i_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  fprintf(stderr, "Frequencies in F must be non decreasing.");
  fprintf(stderr, "\n");
  fprintf(stderr, "Error in %s (line %d)", aFcnName, aLineNum);
  fprintf(stderr, "\n");
  fflush(stderr);
  abort();
}

static void j_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  fprintf(stderr, "Frequencies in F must be in range [0,1].");
  fprintf(stderr, "\n");
  fprintf(stderr, "Error in %s (line %d)", aFcnName, aLineNum);
  fprintf(stderr, "\n");
  fflush(stderr);
  abort();
}

static void minus(double in1_data[], int in1_size[2], const double in2_data[],
                  const int in2_size[2])
{
  double b_in1_data[256];
  int aux_0_1;
  int aux_1_1;
  int b_loop_ub;
  int i;
  int i1;
  int loop_ub;
  int stride_0_0;
  int stride_0_1;
  int stride_1_0;
  int stride_1_1;
  if (in2_size[0] == 1) {
    loop_ub = in1_size[0];
  } else {
    loop_ub = in2_size[0];
  }
  if (in2_size[1] == 1) {
    b_loop_ub = in1_size[1];
  } else {
    b_loop_ub = in2_size[1];
  }
  stride_0_0 = (in1_size[0] != 1);
  stride_0_1 = (in1_size[1] != 1);
  stride_1_0 = (in2_size[0] != 1);
  stride_1_1 = (in2_size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_in1_data[i1 + loop_ub * i] =
          in1_data[i1 * stride_0_0 + in1_size[0] * aux_0_1] -
          in2_data[i1 * stride_1_0 + in2_size[0] * aux_1_1];
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  in1_size[0] = loop_ub;
  in1_size[1] = b_loop_ub;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      in1_data[i1 + in1_size[0] * i] = b_in1_data[i1 + loop_ub * i];
    }
  }
}

static void plus(double in1_data[], int in1_size[2], const double in2_data[],
                 const int in2_size[2])
{
  double b_in1_data[256];
  int aux_0_1;
  int aux_1_1;
  int b_loop_ub;
  int i;
  int i1;
  int loop_ub;
  int stride_0_0;
  int stride_0_1;
  int stride_1_0;
  int stride_1_1;
  if (in2_size[0] == 1) {
    loop_ub = in1_size[0];
  } else {
    loop_ub = in2_size[0];
  }
  if (in2_size[1] == 1) {
    b_loop_ub = in1_size[1];
  } else {
    b_loop_ub = in2_size[1];
  }
  stride_0_0 = (in1_size[0] != 1);
  stride_0_1 = (in1_size[1] != 1);
  stride_1_0 = (in2_size[0] != 1);
  stride_1_1 = (in2_size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_in1_data[i1 + loop_ub * i] =
          in1_data[i1 * stride_0_0 + in1_size[0] * aux_0_1] +
          in2_data[i1 * stride_1_0 + in2_size[0] * aux_1_1];
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  in1_size[0] = loop_ub;
  in1_size[1] = b_loop_ub;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      in1_data[i1 + in1_size[0] * i] = b_in1_data[i1 + loop_ub * i];
    }
  }
}

static void s_rtErrorWithMessageID(const char *r, const char *aFcnName,
                                   int aLineNum)
{
  fprintf(stderr, "Expected %.*s to be finite.", 18, r);
  fprintf(stderr, "\n");
  fprintf(stderr, "Error in %s (line %d)", aFcnName, aLineNum);
  fprintf(stderr, "\n");
  fflush(stderr);
  abort();
}

void firls(const double varargin_2[4], double h_data[], int h_size[2])
{
  static rtBoundsCheckInfo b_emlrtBCI = {
      -1,                                                          /* iFirst */
      -1,                                                          /* iLast */
      9,                                                           /* lineNo */
      47,                                                          /* colNo */
      "",                                                          /* aName */
      "sinc",                                                      /* fName */
      "/Applications/MATLAB_R2023a.app/toolbox/signal/eml/sinc.m", /* pName */
      0 /* checkKind */
  };
  static rtBoundsCheckInfo c_emlrtBCI = {
      -1,                                                          /* iFirst */
      -1,                                                          /* iLast */
      12,                                                          /* lineNo */
      21,                                                          /* colNo */
      "",                                                          /* aName */
      "sinc",                                                      /* fName */
      "/Applications/MATLAB_R2023a.app/toolbox/signal/eml/sinc.m", /* pName */
      0 /* checkKind */
  };
  static rtBoundsCheckInfo d_emlrtBCI = {
      -1,                                                          /* iFirst */
      -1,                                                          /* iLast */
      13,                                                          /* lineNo */
      22,                                                          /* colNo */
      "",                                                          /* aName */
      "sinc",                                                      /* fName */
      "/Applications/MATLAB_R2023a.app/toolbox/signal/eml/sinc.m", /* pName */
      0 /* checkKind */
  };
  static rtBoundsCheckInfo e_emlrtBCI = {
      -1,       /* iFirst */
      -1,       /* iLast */
      310,      /* lineNo */
      31,       /* colNo */
      "",       /* aName */
      "eFirls", /* fName */
      "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/firls.m", /* pName
                                                                        */
      0 /* checkKind */
  };
  static rtBoundsCheckInfo emlrtBCI = {
      -1,                                                          /* iFirst */
      -1,                                                          /* iLast */
      9,                                                           /* lineNo */
      19,                                                          /* colNo */
      "",                                                          /* aName */
      "sinc",                                                      /* fName */
      "/Applications/MATLAB_R2023a.app/toolbox/signal/eml/sinc.m", /* pName */
      0 /* checkKind */
  };
  static rtBoundsCheckInfo f_emlrtBCI = {
      -1,       /* iFirst */
      -1,       /* iLast */
      310,      /* lineNo */
      13,       /* colNo */
      "",       /* aName */
      "eFirls", /* fName */
      "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/firls.m", /* pName
                                                                        */
      0 /* checkKind */
  };
  static rtDoubleCheckInfo b_emlrtDCI = {
      284,     /* lineNo */
      "eFirls" /* fName */
  };
  static rtDoubleCheckInfo c_emlrtDCI = {
      287,     /* lineNo */
      "eFirls" /* fName */
  };
  static rtDoubleCheckInfo d_emlrtDCI = {
      290,     /* lineNo */
      "eFirls" /* fName */
  };
  static rtDoubleCheckInfo e_emlrtDCI = {
      294,     /* lineNo */
      "eFirls" /* fName */
  };
  static rtEqualityCheckInfo b_emlrtECI = {
      2,        /* nDims */
      292,      /* lineNo */
      33,       /* colNo */
      "eFirls", /* fName */
      "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/firls.m" /* pName
                                                                       */
  };
  static rtEqualityCheckInfo c_emlrtECI = {
      1,        /* nDims */
      293,      /* lineNo */
      28,       /* colNo */
      "eFirls", /* fName */
      "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/firls.m" /* pName
                                                                       */
  };
  static rtEqualityCheckInfo d_emlrtECI = {
      2,        /* nDims */
      293,      /* lineNo */
      28,       /* colNo */
      "eFirls", /* fName */
      "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/firls.m" /* pName
                                                                       */
  };
  static rtEqualityCheckInfo e_emlrtECI = {
      1,        /* nDims */
      292,      /* lineNo */
      22,       /* colNo */
      "eFirls", /* fName */
      "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/firls.m" /* pName
                                                                       */
  };
  static rtEqualityCheckInfo emlrtECI = {
      1,        /* nDims */
      292,      /* lineNo */
      33,       /* colNo */
      "eFirls", /* fName */
      "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/firls.m" /* pName
                                                                       */
  };
  static rtEqualityCheckInfo f_emlrtECI = {
      2,        /* nDims */
      292,      /* lineNo */
      22,       /* colNo */
      "eFirls", /* fName */
      "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/firls.m" /* pName
                                                                       */
  };
  static rtEqualityCheckInfo g_emlrtECI = {
      1,        /* nDims */
      292,      /* lineNo */
      17,       /* colNo */
      "eFirls", /* fName */
      "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/firls.m" /* pName
                                                                       */
  };
  static rtEqualityCheckInfo h_emlrtECI = {
      2,        /* nDims */
      292,      /* lineNo */
      17,       /* colNo */
      "eFirls", /* fName */
      "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/firls.m" /* pName
                                                                       */
  };
  static rtRunTimeErrorInfo k_emlrtRTEI = {
      14,              /* lineNo */
      "validatefinite" /* fName */
  };
  static rtRunTimeErrorInfo l_emlrtRTEI = {
      159,     /* lineNo */
      "eFirls" /* fName */
  };
  static rtRunTimeErrorInfo m_emlrtRTEI = {
      207,     /* lineNo */
      "eFirls" /* fName */
  };
  static const signed char A[4] = {1, 1, 0, 0};
  double G_data[256];
  double b_data[16];
  double y_tmp_data[16];
  int G_size[2];
  int a_size[2];
  int b_y_tmp_size[2];
  int tmp_size[2];
  int y_tmp_size[2];
  int i;
  int i1;
  int i2;
  int k;
  int s;
  boolean_T exitg1;
  boolean_T p;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 4)) {
    if ((!rtIsInf(varargin_2[k])) && (!rtIsNaN(varargin_2[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    s_rtErrorWithMessageID("input number 2, f,", k_emlrtRTEI.fName,
                           k_emlrtRTEI.lineNo);
  }
  if (varargin_2[0] > 1.0) {
    j_rtErrorWithMessageID(l_emlrtRTEI.fName, l_emlrtRTEI.lineNo);
  } else {
    double max_freq[4];
    double b_y1[3];
    double b0;
    int iv[2];
    int I1_size_idx_0;
    int I1_size_idx_1;
    int I2_size_idx_0;
    int I2_size_idx_1;
    signed char I1_data[256];
    signed char I2_data[256];
    signed char k_tmp_data[16];
    signed char m_s_tmp;
    max_freq[0] = varargin_2[0] / 2.0;
    max_freq[1] = varargin_2[1] / 2.0;
    max_freq[2] = varargin_2[2] / 2.0;
    max_freq[3] = varargin_2[3] / 2.0;
    b_y1[0] = max_freq[1];
    b_y1[1] = max_freq[2] - max_freq[1];
    b_y1[2] = max_freq[3] - max_freq[2];
    p = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (b_y1[k] < 0.0) {
        p = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (p) {
      i_rtErrorWithMessageID(m_emlrtRTEI.fName, m_emlrtRTEI.lineNo);
    }
    for (i = 0; i < 16; i++) {
      k_tmp_data[i] = (signed char)i;
    }
    p = (b_y1[1] != 0.0);
    if (p) {
      I1_size_idx_0 = 16;
      I1_size_idx_1 = 16;
      I2_size_idx_0 = 16;
      I2_size_idx_1 = 16;
      for (i = 0; i < 16; i++) {
        for (i1 = 0; i1 < 16; i1++) {
          m_s_tmp = k_tmp_data[i1];
          k = i1 + 16 * i;
          I1_data[k] = (signed char)(m_s_tmp + i);
          I2_data[k] = (signed char)(m_s_tmp - i);
        }
      }
      G_size[0] = 16;
      G_size[1] = 16;
      memset(&G_data[0], 0, 256U * sizeof(double));
    } else {
      I1_size_idx_0 = 0;
      I1_size_idx_1 = 0;
      I2_size_idx_0 = 0;
      I2_size_idx_1 = 0;
      G_size[0] = 0;
      G_size[1] = 0;
    }
    iv[0] = 1;
    iv[1] = 15;
    indexShapeCheck(16, iv);
    b0 = 0.0;
    memset(&b_data[0], 0, 15U * sizeof(double));
    for (s = 0; s < 2; s++) {
      double b_y_data[15];
      double y_data[15];
      double a;
      double b1;
      double b1_tmp;
      double b_m_s_tmp;
      double c_m_s_tmp;
      double d;
      double d1;
      double m_s;
      int b_s;
      b_s = (s << 1) + 1;
      m_s_tmp = A[b_s - 1];
      b_m_s_tmp = max_freq[b_s - 1];
      d = max_freq[b_s];
      c_m_s_tmp = d - b_m_s_tmp;
      m_s = (double)(A[b_s] - m_s_tmp) / c_m_s_tmp;
      b1_tmp = m_s * b_m_s_tmp;
      b1 = (double)m_s_tmp - b1_tmp;
      d1 = ((double)b_s + 1.0) / 2.0;
      i = (int)floor(d1);
      if (d1 != i) {
        rtIntegerError(d1, &b_emlrtDCI);
      }
      b0 += b1 * c_m_s_tmp + m_s / 2.0 * (d * d - b_m_s_tmp * b_m_s_tmp);
      for (k = 0; k < 15; k++) {
        d = 6.2831853071795862 * (double)k_tmp_data[k + 1];
        y_data[k] = cos(d * max_freq[b_s]);
        b_y_data[k] = cos(d * b_m_s_tmp);
      }
      i1 = (int)d1;
      if (i1 != i) {
        rtIntegerError(d1, &c_emlrtDCI);
      }
      a = m_s / 39.478417604357432;
      d = max_freq[b_s];
      m_s = d * (m_s * d + b1);
      c_m_s_tmp = b_m_s_tmp * (b1_tmp + b1);
      for (k = 0; k < 15; k++) {
        m_s_tmp = k_tmp_data[k + 1];
        b_data[k] +=
            a * (y_data[k] - b_y_data[k]) / (double)(m_s_tmp * m_s_tmp);
        i2 = 2 * m_s_tmp;
        d = (double)i2 * max_freq[b_s];
        y_data[k] = d;
        if (fabs(d) < 1.0020841800044864E-292) {
          y_data[k] = 1.0;
        } else {
          d *= 3.1415926535897931;
          d = sin(d) / d;
          y_data[k] = d;
        }
        d = (double)i2 * b_m_s_tmp;
        b_y_data[k] = d;
        if (fabs(d) < 1.0020841800044864E-292) {
          b_y_data[k] = 1.0;
        } else {
          d *= 3.1415926535897931;
          d = sin(d) / d;
          b_y_data[k] = d;
        }
      }
      if (i1 != i) {
        rtIntegerError(d1, &d_emlrtDCI);
      }
      for (i2 = 0; i2 < 15; i2++) {
        b_data[i2] += m_s * y_data[i2] - c_m_s_tmp * b_y_data[i2];
      }
      if (p) {
        double a_data[256];
        double b_y_tmp_data[256];
        double c_y_tmp_data[256];
        double tmp_data[256];
        int loop_ub_tmp;
        boolean_T b;
        y_tmp_size[0] = I1_size_idx_0;
        y_tmp_size[1] = I1_size_idx_1;
        loop_ub_tmp = I1_size_idx_0 * I1_size_idx_1;
        a_size[0] = I1_size_idx_0;
        a_size[1] = I1_size_idx_1;
        for (i2 = 0; i2 < loop_ub_tmp; i2++) {
          k = 2 * I1_data[i2];
          b_y_tmp_data[i2] = k;
          a_data[i2] = (double)k * max_freq[b_s];
        }
        for (k = 0; k < loop_ub_tmp; k++) {
          if (k + 1 > loop_ub_tmp) {
            rtDynamicBoundsError(k + 1, 1, loop_ub_tmp, &emlrtBCI);
          }
          d = a_data[k];
          if (fabs(d) < 1.0020841800044864E-292) {
            if (k + 1 > loop_ub_tmp) {
              rtDynamicBoundsError(k + 1, 1, loop_ub_tmp, &b_emlrtBCI);
            }
            a_data[k] = 1.0;
          } else {
            if (k + 1 > loop_ub_tmp) {
              rtDynamicBoundsError(k + 1, 1, loop_ub_tmp, &c_emlrtBCI);
            }
            d *= 3.1415926535897931;
            if (k + 1 > loop_ub_tmp) {
              rtDynamicBoundsError(k + 1, 1, loop_ub_tmp, &d_emlrtBCI);
            }
            d = sin(d) / d;
            a_data[k] = d;
          }
        }
        b_y_tmp_size[0] = I2_size_idx_0;
        b_y_tmp_size[1] = I2_size_idx_1;
        tmp_size[0] = I2_size_idx_0;
        tmp_size[1] = I2_size_idx_1;
        for (i2 = 0; i2 < loop_ub_tmp; i2++) {
          k = 2 * I2_data[i2];
          c_y_tmp_data[i2] = k;
          tmp_data[i2] = (double)k * max_freq[b_s];
        }
        for (k = 0; k < loop_ub_tmp; k++) {
          if (k + 1 > loop_ub_tmp) {
            rtDynamicBoundsError(k + 1, 1, loop_ub_tmp, &emlrtBCI);
          }
          d = tmp_data[k];
          if (fabs(d) < 1.0020841800044864E-292) {
            if (k + 1 > loop_ub_tmp) {
              rtDynamicBoundsError(k + 1, 1, loop_ub_tmp, &b_emlrtBCI);
            }
            tmp_data[k] = 1.0;
          } else {
            if (k + 1 > loop_ub_tmp) {
              rtDynamicBoundsError(k + 1, 1, loop_ub_tmp, &c_emlrtBCI);
            }
            d *= 3.1415926535897931;
            if (k + 1 > loop_ub_tmp) {
              rtDynamicBoundsError(k + 1, 1, loop_ub_tmp, &d_emlrtBCI);
            }
            d = sin(d) / d;
            tmp_data[k] = d;
          }
        }
        b = ((I1_size_idx_0 != I2_size_idx_0) &&
             ((I1_size_idx_0 != 1) && (I2_size_idx_0 != 1)));
        if (b) {
          emlrtDimSizeImpxCheckR2021b(I1_size_idx_0, I2_size_idx_0, &emlrtECI);
          emlrtDimSizeImpxCheckR2021b(I1_size_idx_1, I2_size_idx_1,
                                      &b_emlrtECI);
        }
        for (i2 = 0; i2 < loop_ub_tmp; i2++) {
          b_y_tmp_data[i2] *= b_m_s_tmp;
        }
        for (k = 0; k < loop_ub_tmp; k++) {
          if (k + 1 > loop_ub_tmp) {
            rtDynamicBoundsError(k + 1, 1, loop_ub_tmp, &emlrtBCI);
          }
          d = b_y_tmp_data[k];
          if (fabs(d) < 1.0020841800044864E-292) {
            if (k + 1 > loop_ub_tmp) {
              rtDynamicBoundsError(k + 1, 1, loop_ub_tmp, &b_emlrtBCI);
            }
            b_y_tmp_data[k] = 1.0;
          } else {
            if (k + 1 > loop_ub_tmp) {
              rtDynamicBoundsError(k + 1, 1, loop_ub_tmp, &c_emlrtBCI);
            }
            d *= 3.1415926535897931;
            if (k + 1 > loop_ub_tmp) {
              rtDynamicBoundsError(k + 1, 1, loop_ub_tmp, &d_emlrtBCI);
            }
            d = sin(d) / d;
            b_y_tmp_data[k] = d;
          }
        }
        for (i2 = 0; i2 < loop_ub_tmp; i2++) {
          c_y_tmp_data[i2] *= b_m_s_tmp;
        }
        for (k = 0; k < loop_ub_tmp; k++) {
          if (k + 1 > loop_ub_tmp) {
            rtDynamicBoundsError(k + 1, 1, loop_ub_tmp, &emlrtBCI);
          }
          d = c_y_tmp_data[k];
          if (fabs(d) < 1.0020841800044864E-292) {
            if (k + 1 > loop_ub_tmp) {
              rtDynamicBoundsError(k + 1, 1, loop_ub_tmp, &b_emlrtBCI);
            }
            c_y_tmp_data[k] = 1.0;
          } else {
            if (k + 1 > loop_ub_tmp) {
              rtDynamicBoundsError(k + 1, 1, loop_ub_tmp, &c_emlrtBCI);
            }
            d *= 3.1415926535897931;
            if (k + 1 > loop_ub_tmp) {
              rtDynamicBoundsError(k + 1, 1, loop_ub_tmp, &d_emlrtBCI);
            }
            d = sin(d) / d;
            c_y_tmp_data[k] = d;
          }
        }
        if (b) {
          emlrtDimSizeImpxCheckR2021b(I1_size_idx_0, I2_size_idx_0,
                                      &c_emlrtECI);
          emlrtDimSizeImpxCheckR2021b(I1_size_idx_1, I2_size_idx_1,
                                      &d_emlrtECI);
        }
        a = 0.5 * max_freq[b_s];
        b = ((I1_size_idx_0 == I2_size_idx_0) &&
             (I1_size_idx_1 == I2_size_idx_1));
        if (b) {
          for (i2 = 0; i2 < loop_ub_tmp; i2++) {
            a_data[i2] = a * (a_data[i2] + tmp_data[i2]);
          }
        } else {
          b_binary_expand_op(a_data, a_size, a, tmp_data, tmp_size);
        }
        a = 0.5 * b_m_s_tmp;
        if (b) {
          for (i2 = 0; i2 < loop_ub_tmp; i2++) {
            b_y_tmp_data[i2] = a * (b_y_tmp_data[i2] + c_y_tmp_data[i2]);
          }
        } else {
          b_binary_expand_op(b_y_tmp_data, y_tmp_size, a, c_y_tmp_data,
                             b_y_tmp_size);
        }
        if ((a_size[0] != y_tmp_size[0]) &&
            ((a_size[0] != 1) && (y_tmp_size[0] != 1))) {
          emlrtDimSizeImpxCheckR2021b(a_size[0], y_tmp_size[0], &e_emlrtECI);
        }
        if ((a_size[1] != y_tmp_size[1]) &&
            ((a_size[1] != 1) && (y_tmp_size[1] != 1))) {
          emlrtDimSizeImpxCheckR2021b(a_size[1], y_tmp_size[1], &f_emlrtECI);
        }
        if (i1 != i) {
          rtIntegerError(d1, &e_emlrtDCI);
        }
        if ((a_size[0] == y_tmp_size[0]) && (a_size[1] == y_tmp_size[1])) {
          k = a_size[0] * a_size[1];
          for (i = 0; i < k; i++) {
            a_data[i] -= b_y_tmp_data[i];
          }
        } else {
          minus(a_data, a_size, b_y_tmp_data, y_tmp_size);
        }
        if ((G_size[0] != a_size[0]) &&
            ((G_size[0] != 1) && (a_size[0] != 1))) {
          emlrtDimSizeImpxCheckR2021b(G_size[0], a_size[0], &g_emlrtECI);
        }
        if ((G_size[1] != a_size[1]) &&
            ((G_size[1] != 1) && (a_size[1] != 1))) {
          emlrtDimSizeImpxCheckR2021b(G_size[1], a_size[1], &h_emlrtECI);
        }
        if ((G_size[0] == a_size[0]) && (G_size[1] == a_size[1])) {
          k = G_size[0] * G_size[1];
          for (i = 0; i < k; i++) {
            G_data[i] += a_data[i];
          }
        } else {
          plus(G_data, G_size, a_data, a_size);
        }
      }
    }
    y_tmp_data[0] = b0;
    memcpy(&y_tmp_data[1], &b_data[0], 15U * sizeof(double));
    memcpy(&b_data[0], &y_tmp_data[0], 16U * sizeof(double));
    if (p) {
      k = mldivide(G_data, G_size, b_data, y_tmp_data);
    } else {
      k = 16;
      for (i = 0; i < 16; i++) {
        y_tmp_data[i] = 4.0 * b_data[i];
      }
      y_tmp_data[0] /= 2.0;
    }
    b_indexShapeCheck(k);
    b_indexShapeCheck(k);
    if (k < 1) {
      rtDynamicBoundsError(1, 1, k, &e_emlrtBCI);
    }
    h_size[0] = 1;
    h_size[1] = 31;
    for (i = 0; i < 15; i++) {
      if (16 - i > k) {
        rtDynamicBoundsError(16 - i, 1, k, &f_emlrtBCI);
      }
      h_data[i] = y_tmp_data[15 - i] / 2.0;
    }
    h_data[15] = y_tmp_data[0];
    for (i = 0; i < 15; i++) {
      if (i + 2 > k) {
        rtDynamicBoundsError(i + 2, 1, k, &f_emlrtBCI);
      }
      h_data[i + 16] = y_tmp_data[i + 1] / 2.0;
    }
  }
}

/* End of code generation (firls.c) */
