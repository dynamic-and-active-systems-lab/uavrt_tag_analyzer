/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * islinphase.c
 *
 * Code generation for function 'islinphase'
 *
 */

/* Include files */
#include "islinphase.h"
#include "find.h"
#include "indexShapeCheck.h"
#include "levdown.h"
#include "minOrMax.h"
#include "rt_nonfinite.h"
#include "uavrt_tag_analyzer_emxutil.h"
#include "uavrt_tag_analyzer_internal_types.h"
#include "uavrt_tag_analyzer_rtwutil.h"
#include "uavrt_tag_analyzer_types.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <stdio.h>
#include <string.h>

/* Function Declarations */
static void d_binary_expand_op(emxArray_real_T *in1, const double in2_data[],
                               const int in2_size[2], int in3, int in4,
                               int in5);

static boolean_T determineiflinphase(const double b_data[],
                                     const int b_size[2]);

static void e_binary_expand_op(emxArray_real_T *in1, const double in2_data[],
                               const int in2_size[2], int in3, int in4,
                               int in5);

static void n_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void rtSizeEq1DError(const int aDim1, const int aDim2,
                            const rtEqualityCheckInfo *aInfo);

/* Function Definitions */
static void d_binary_expand_op(emxArray_real_T *in1, const double in2_data[],
                               const int in2_size[2], int in3, int in4, int in5)
{
  double *in1_data;
  int i;
  int loop_ub;
  int stride_0_1;
  int stride_1_1;
  i = in1->size[0] * in1->size[1];
  in1->size[0] = 1;
  emxEnsureCapacity_real_T(in1, i);
  i = div_s32((in5 - in3) + 1, in4) + 1;
  if (i == 1) {
    loop_ub = in2_size[1];
  } else {
    loop_ub = i;
  }
  stride_0_1 = in1->size[0] * in1->size[1];
  in1->size[1] = loop_ub;
  emxEnsureCapacity_real_T(in1, stride_0_1);
  in1_data = in1->data;
  stride_0_1 = (in2_size[1] != 1);
  stride_1_1 = (i != 1);
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] =
        in2_data[i * stride_0_1] + in2_data[(in3 + in4 * (i * stride_1_1)) - 1];
  }
}

static boolean_T determineiflinphase(const double b_data[], const int b_size[2])
{
  static rtBoundsCheckInfo b_emlrtBCI = {
      -1,            /* iFirst */
      -1,            /* iLast */
      127,           /* lineNo */
      34,            /* colNo */
      "",            /* aName */
      "removezeros", /* fName */
      "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/+signal/+internal/"
      "islinphase.m", /* pName */
      0               /* checkKind */
  };
  static rtBoundsCheckInfo c_emlrtBCI = {
      -1,            /* iFirst */
      -1,            /* iLast */
      127,           /* lineNo */
      14,            /* colNo */
      "",            /* aName */
      "removezeros", /* fName */
      "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/+signal/+internal/"
      "islinphase.m", /* pName */
      0               /* checkKind */
  };
  static rtBoundsCheckInfo d_emlrtBCI = {
      -1,            /* iFirst */
      -1,            /* iLast */
      127,           /* lineNo */
      26,            /* colNo */
      "",            /* aName */
      "removezeros", /* fName */
      "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/+signal/+internal/"
      "islinphase.m", /* pName */
      0               /* checkKind */
  };
  static rtBoundsCheckInfo emlrtBCI = {
      -1,            /* iFirst */
      -1,            /* iLast */
      127,           /* lineNo */
      23,            /* colNo */
      "",            /* aName */
      "removezeros", /* fName */
      "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/+signal/+internal/"
      "islinphase.m", /* pName */
      0               /* checkKind */
  };
  static rtEqualityCheckInfo b_emlrtECI = {
      2,              /* nDims */
      109,            /* lineNo */
      24,             /* colNo */
      "symmetrytest", /* fName */
      "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/+signal/+internal/"
      "islinphase.m" /* pName */
  };
  static rtEqualityCheckInfo emlrtECI = {
      2,              /* nDims */
      107,            /* lineNo */
      20,             /* colNo */
      "symmetrytest", /* fName */
      "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/+signal/+internal/"
      "islinphase.m" /* pName */
  };
  static const char cv1[128] = {
      '\x00', '\x01', '\x02', '\x03', '\x04', '\x05', '\x06', '\a',   '\b',
      '\t',   '\n',   '\v',   '\f',   '\r',   '\x0e', '\x0f', '\x10', '\x11',
      '\x12', '\x13', '\x14', '\x15', '\x16', '\x17', '\x18', '\x19', '\x1a',
      '\x1b', '\x1c', '\x1d', '\x1e', '\x1f', ' ',    '!',    '\"',   '#',
      '$',    '%',    '&',    '\'',   '(',    ')',    '*',    '+',    ',',
      '-',    '.',    '/',    '0',    '1',    '2',    '3',    '4',    '5',
      '6',    '7',    '8',    '9',    ':',    ';',    '<',    '=',    '>',
      '?',    '@',    'a',    'b',    'c',    'd',    'e',    'f',    'g',
      'h',    'i',    'j',    'k',    'l',    'm',    'n',    'o',    'p',
      'q',    'r',    's',    't',    'u',    'v',    'w',    'x',    'y',
      'z',    '[',    '\\',   ']',    '^',    '_',    '`',    'a',    'b',
      'c',    'd',    'e',    'f',    'g',    'h',    'i',    'j',    'k',
      'l',    'm',    'n',    'o',    'p',    'q',    'r',    's',    't',
      'u',    'v',    'w',    'x',    'y',    'z',    '{',    '|',    '}',
      '~',    '\x7f'};
  static const char cv3[13] = {'a', 'n', 't', 'i', 's', 'y', 'm',
                               'm', 'e', 't', 'r', 'i', 'c'};
  static const char cv[9] = {'s', 'y', 'm', 'm', 'e', 't', 'r', 'i', 'c'};
  static const char cv2[4] = {'n', 'o', 'n', 'e'};
  emxArray_real_T *x;
  emxArray_real_T *y;
  double bIn_data[31];
  double *x_data;
  double *y_data;
  int bIn_size[2];
  int i;
  int idx;
  int ii_data;
  boolean_T islinphaseflag;
  if (b_size[1] == 1) {
    islinphaseflag = true;
  } else {
    double maxval;
    int b_y[2];
    int nx;
    char symstr_data[13];
    boolean_T b_bool;
    nx = b_size[1];
    emxInit_real_T(&y, 2);
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = b_size[1];
    emxEnsureCapacity_real_T(y, i);
    y_data = y->data;
    for (idx = 0; idx < nx; idx++) {
      y_data[idx] = fabs(b_data[idx]);
    }
    b_y[0] = (*(int(*)[2])y->size)[0];
    b_y[1] = (*(int(*)[2])y->size)[1];
    maxval = maximum((double *)y->data, b_y);
    if (maxval == 0.0) {
      bIn_size[0] = 1;
      bIn_size[1] = 1;
      bIn_data[0] = 0.0;
    } else {
      int startidx_data;
      int startidx_size_idx_1;
      signed char stopidx_data;
      boolean_T exitg1;
      bIn_size[0] = 1;
      bIn_size[1] = b_size[1];
      nx = b_size[1];
      if (nx - 1 >= 0) {
        memcpy(&bIn_data[0], &b_data[0], (unsigned int)nx * sizeof(double));
      }
      eml_find(bIn_data, bIn_size, (int *)&ii_data, b_y);
      startidx_size_idx_1 = b_y[1];
      nx = b_y[1];
      for (i = 0; i < nx; i++) {
        startidx_data = ii_data;
      }
      nx = b_size[1];
      idx = 0;
      b_y[1] = 1;
      exitg1 = false;
      while ((!exitg1) && (nx > 0)) {
        if (b_data[nx - 1] != 0.0) {
          idx = 1;
          ii_data = nx;
          exitg1 = true;
        } else {
          nx--;
        }
      }
      if (idx == 0) {
        b_y[1] = 0;
      }
      nx = b_y[1];
      for (i = 0; i < nx; i++) {
        stopidx_data = (signed char)ii_data;
      }
      if (startidx_size_idx_1 < 1) {
        rtDynamicBoundsError(1, 1, startidx_size_idx_1, &emlrtBCI);
      }
      if (b_y[1] < 1) {
        rtDynamicBoundsError(1, 1, 0, &b_emlrtBCI);
      }
      if (startidx_data > stopidx_data) {
        i = 0;
        idx = 0;
      } else {
        if ((startidx_data < 1) || (startidx_data > b_size[1])) {
          rtDynamicBoundsError(startidx_data, 1, b_size[1], &c_emlrtBCI);
        }
        i = startidx_data - 1;
        if (stopidx_data > b_size[1]) {
          rtDynamicBoundsError(stopidx_data, 1, b_size[1], &d_emlrtBCI);
        }
        idx = stopidx_data;
      }
      bIn_size[0] = 1;
      nx = idx - i;
      bIn_size[1] = nx;
      for (idx = 0; idx < nx; idx++) {
        bIn_data[idx] = b_data[i + idx];
      }
    }
    if (bIn_size[1] < 1) {
      i = 0;
      idx = 1;
      ii_data = -1;
    } else {
      i = bIn_size[1] - 1;
      idx = -1;
      ii_data = 0;
    }
    nx = div_s32(ii_data - i, idx) + 1;
    if ((bIn_size[1] != nx) && ((bIn_size[1] != 1) && (nx != 1))) {
      emlrtDimSizeImpxCheckR2021b(bIn_size[1], nx, &emlrtECI);
    }
    emxInit_real_T(&x, 2);
    if (bIn_size[1] == nx) {
      ii_data = x->size[0] * x->size[1];
      x->size[0] = 1;
      x->size[1] = bIn_size[1];
      emxEnsureCapacity_real_T(x, ii_data);
      x_data = x->data;
      nx = bIn_size[1];
      for (ii_data = 0; ii_data < nx; ii_data++) {
        x_data[ii_data] = bIn_data[ii_data] - bIn_data[i + idx * ii_data];
      }
    } else {
      e_binary_expand_op(x, bIn_data, bIn_size, i + 1, idx, ii_data);
      x_data = x->data;
    }
    nx = x->size[1];
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = (signed char)x->size[1];
    emxEnsureCapacity_real_T(y, i);
    y_data = y->data;
    for (idx = 0; idx < nx; idx++) {
      y_data[idx] = fabs(x_data[idx]);
    }
    b_y[0] = (*(int(*)[2])y->size)[0];
    b_y[1] = (*(int(*)[2])y->size)[1];
    maxval = maximum((double *)y->data, b_y);
    if (maxval <= 0.0) {
      nx = 9;
      for (i = 0; i < 9; i++) {
        symstr_data[i] = cv[i];
      }
    } else {
      if (bIn_size[1] < 1) {
        i = 0;
        idx = 1;
        ii_data = -1;
      } else {
        i = bIn_size[1] - 1;
        idx = -1;
        ii_data = 0;
      }
      nx = div_s32(ii_data - i, idx) + 1;
      if ((bIn_size[1] != nx) && ((bIn_size[1] != 1) && (nx != 1))) {
        emlrtDimSizeImpxCheckR2021b(bIn_size[1], nx, &b_emlrtECI);
      }
      if (bIn_size[1] == nx) {
        ii_data = x->size[0] * x->size[1];
        x->size[0] = 1;
        x->size[1] = bIn_size[1];
        emxEnsureCapacity_real_T(x, ii_data);
        x_data = x->data;
        nx = bIn_size[1];
        for (ii_data = 0; ii_data < nx; ii_data++) {
          x_data[ii_data] = bIn_data[ii_data] + bIn_data[i + idx * ii_data];
        }
      } else {
        d_binary_expand_op(x, bIn_data, bIn_size, i + 1, idx, ii_data);
        x_data = x->data;
      }
      nx = x->size[1];
      i = y->size[0] * y->size[1];
      y->size[0] = 1;
      y->size[1] = (signed char)x->size[1];
      emxEnsureCapacity_real_T(y, i);
      y_data = y->data;
      for (idx = 0; idx < nx; idx++) {
        y_data[idx] = fabs(x_data[idx]);
      }
      b_y[0] = (*(int(*)[2])y->size)[0];
      b_y[1] = (*(int(*)[2])y->size)[1];
      maxval = maximum((double *)y->data, b_y);
      if (maxval <= 0.0) {
        nx = 13;
        for (i = 0; i < 13; i++) {
          symstr_data[i] = cv3[i];
        }
      } else {
        nx = 4;
        symstr_data[0] = 'n';
        symstr_data[1] = 'o';
        symstr_data[2] = 'n';
        symstr_data[3] = 'e';
      }
    }
    emxFree_real_T(&y);
    emxFree_real_T(&x);
    b_bool = false;
    if (nx == 4) {
      nx = 0;
      int exitg2;
      do {
        exitg2 = 0;
        if (nx < 4) {
          if (cv1[(int)symstr_data[nx]] != cv1[(int)cv2[nx]]) {
            exitg2 = 1;
          } else {
            nx++;
          }
        } else {
          b_bool = true;
          exitg2 = 1;
        }
      } while (exitg2 == 0);
    }
    islinphaseflag = !b_bool;
  }
  return islinphaseflag;
}

static void e_binary_expand_op(emxArray_real_T *in1, const double in2_data[],
                               const int in2_size[2], int in3, int in4, int in5)
{
  double *in1_data;
  int i;
  int loop_ub;
  int stride_0_1;
  int stride_1_1;
  i = in1->size[0] * in1->size[1];
  in1->size[0] = 1;
  emxEnsureCapacity_real_T(in1, i);
  i = div_s32((in5 - in3) + 1, in4) + 1;
  if (i == 1) {
    loop_ub = in2_size[1];
  } else {
    loop_ub = i;
  }
  stride_0_1 = in1->size[0] * in1->size[1];
  in1->size[1] = loop_ub;
  emxEnsureCapacity_real_T(in1, stride_0_1);
  in1_data = in1->data;
  stride_0_1 = (in2_size[1] != 1);
  stride_1_1 = (i != 1);
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] =
        in2_data[i * stride_0_1] - in2_data[(in3 + in4 * (i * stride_1_1)) - 1];
  }
}

static void n_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  fprintf(stderr, "Polynomial cannot contain only zeros.");
  fprintf(stderr, "\n");
  fprintf(stderr, "Error in %s (line %d)", aFcnName, aLineNum);
  fprintf(stderr, "\n");
  fflush(stderr);
  abort();
}

static void rtSizeEq1DError(const int aDim1, const int aDim2,
                            const rtEqualityCheckInfo *aInfo)
{
  fprintf(stderr, "Sizes mismatch: %d ~= %d.", aDim1, aDim2);
  fprintf(stderr, "\n");
  rtReportErrorLocation(aInfo->fName, aInfo->lineNo);
  fflush(stderr);
  abort();
}

boolean_T islinphase(const double b_data[], const int b_size[2],
                     const double a_data[], const int a_size[2])
{
  static rtBoundsCheckInfo b_emlrtBCI = {
      -1,         /* iFirst */
      -1,         /* iLast */
      11,         /* lineNo */
      24,         /* colNo */
      "",         /* aName */
      "isstable", /* fName */
      "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/+signal/+internal/"
      "isstable.m", /* pName */
      0             /* checkKind */
  };
  static rtBoundsCheckInfo c_emlrtBCI = {
      -1,         /* iFirst */
      -1,         /* iLast */
      25,         /* lineNo */
      10,         /* colNo */
      "",         /* aName */
      "isstable", /* fName */
      "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/+signal/+internal/"
      "isstable.m", /* pName */
      0             /* checkKind */
  };
  static rtBoundsCheckInfo d_emlrtBCI = {
      -1,         /* iFirst */
      -1,         /* iLast */
      30,         /* lineNo */
      13,         /* colNo */
      "",         /* aName */
      "isstable", /* fName */
      "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/+signal/+internal/"
      "isstable.m", /* pName */
      0             /* checkKind */
  };
  static rtBoundsCheckInfo e_emlrtBCI = {
      -1,        /* iFirst */
      -1,        /* iLast */
      98,        /* lineNo */
      67,        /* colNo */
      "",        /* aName */
      "poly2rc", /* fName */
      "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/poly2rc.m", /* pName
                                                                          */
      0 /* checkKind */
  };
  static rtBoundsCheckInfo emlrtBCI = {
      -1,      /* iFirst */
      -1,      /* iLast */
      22,      /* lineNo */
      10,      /* colNo */
      "",      /* aName */
      "isfir", /* fName */
      "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/+signal/+internal/"
      "isfir.m", /* pName */
      0          /* checkKind */
  };
  static rtBoundsCheckInfo f_emlrtBCI = {
      -1,        /* iFirst */
      -1,        /* iLast */
      98,        /* lineNo */
      74,        /* colNo */
      "",        /* aName */
      "poly2rc", /* fName */
      "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/poly2rc.m", /* pName
                                                                          */
      0 /* checkKind */
  };
  static rtBoundsCheckInfo g_emlrtBCI = {
      -1,        /* iFirst */
      -1,        /* iLast */
      98,        /* lineNo */
      44,        /* colNo */
      "",        /* aName */
      "poly2rc", /* fName */
      "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/poly2rc.m", /* pName
                                                                          */
      0 /* checkKind */
  };
  static rtBoundsCheckInfo h_emlrtBCI =
      {
          -1,        /* iFirst */
          -1,        /* iLast */
          41,        /* lineNo */
          13,        /* colNo */
          "",        /* aName */
          "levdown", /* fName */
          "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/private/"
          "levdown.m", /* pName */
          0            /* checkKind */
      };
  static rtBoundsCheckInfo i_emlrtBCI = {
      -1,        /* iFirst */
      -1,        /* iLast */
      98,        /* lineNo */
      28,        /* colNo */
      "",        /* aName */
      "poly2rc", /* fName */
      "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/poly2rc.m", /* pName
                                                                          */
      0 /* checkKind */
  };
  static rtBoundsCheckInfo j_emlrtBCI = {
      -1,        /* iFirst */
      -1,        /* iLast */
      103,       /* lineNo */
      20,        /* colNo */
      "",        /* aName */
      "poly2rc", /* fName */
      "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/poly2rc.m", /* pName
                                                                          */
      0 /* checkKind */
  };
  static rtBoundsCheckInfo k_emlrtBCI = {
      -1,        /* iFirst */
      -1,        /* iLast */
      103,       /* lineNo */
      8,         /* colNo */
      "",        /* aName */
      "poly2rc", /* fName */
      "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/poly2rc.m", /* pName
                                                                          */
      0 /* checkKind */
  };
  static rtBoundsCheckInfo l_emlrtBCI = {
      -1,        /* iFirst */
      -1,        /* iLast */
      98,        /* lineNo */
      19,        /* colNo */
      "",        /* aName */
      "poly2rc", /* fName */
      "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/poly2rc.m", /* pName
                                                                          */
      0 /* checkKind */
  };
  static rtBoundsCheckInfo m_emlrtBCI =
      {
          -1,        /* iFirst */
          -1,        /* iLast */
          52,        /* lineNo */
          38,        /* colNo */
          "",        /* aName */
          "levdown", /* fName */
          "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/private/"
          "levdown.m", /* pName */
          0            /* checkKind */
      };
  static rtBoundsCheckInfo n_emlrtBCI =
      {
          -1,        /* iFirst */
          -1,        /* iLast */
          52,        /* lineNo */
          16,        /* colNo */
          "",        /* aName */
          "levdown", /* fName */
          "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/private/"
          "levdown.m", /* pName */
          0            /* checkKind */
      };
  static rtBoundsCheckInfo o_emlrtBCI = {
      -1,             /* iFirst */
      -1,             /* iLast */
      66,             /* lineNo */
      16,             /* colNo */
      "",             /* aName */
      "ispolystable", /* fName */
      "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/+signal/+internal/"
      "isstable.m", /* pName */
      0             /* checkKind */
  };
  static rtBoundsCheckInfo p_emlrtBCI = {
      -1,             /* iFirst */
      -1,             /* iLast */
      66,             /* lineNo */
      29,             /* colNo */
      "",             /* aName */
      "ispolystable", /* fName */
      "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/+signal/+internal/"
      "isstable.m", /* pName */
      0             /* checkKind */
  };
  static rtBoundsCheckInfo q_emlrtBCI = {
      -1,         /* iFirst */
      -1,         /* iLast */
      28,         /* lineNo */
      11,         /* colNo */
      "",         /* aName */
      "isstable", /* fName */
      "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/+signal/+internal/"
      "isstable.m", /* pName */
      0             /* checkKind */
  };
  static rtBoundsCheckInfo r_emlrtBCI = {
      -1,         /* iFirst */
      -1,         /* iLast */
      20,         /* lineNo */
      10,         /* colNo */
      "",         /* aName */
      "isstable", /* fName */
      "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/+signal/+internal/"
      "isstable.m", /* pName */
      0             /* checkKind */
  };
  static rtEqualityCheckInfo b_emlrtECI = {
      -1,        /* nDims */
      98,        /* lineNo */
      10,        /* colNo */
      "poly2rc", /* fName */
      "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/poly2rc.m" /* pName
                                                                         */
  };
  static rtEqualityCheckInfo emlrtECI =
      {
          1,         /* nDims */
          52,        /* lineNo */
          9,         /* colNo */
          "levdown", /* fName */
          "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/private/"
          "levdown.m" /* pName */
      };
  static rtRunTimeErrorInfo k_emlrtRTEI = {
      17,        /* lineNo */
      "isstable" /* fName */
  };
  double acur_data[32];
  double a2_data[31];
  double temp_a1_data[31];
  double k_data[30];
  int b_i;
  int c_i;
  int i;
  int i1;
  int i2;
  int idxNonZero;
  int k;
  int n;
  boolean_T errLevdown_data[30];
  boolean_T exitg1;
  boolean_T firflag;
  boolean_T islinphaseflag;
  n = a_size[1];
  idxNonZero = 0;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i <= n - 1)) {
    b_i = n - i;
    if ((b_i < 1) || (b_i > a_size[1])) {
      rtDynamicBoundsError(b_i, 1, a_size[1], &emlrtBCI);
    }
    if (a_data[b_i - 1] != 0.0) {
      idxNonZero = b_i;
      exitg1 = true;
    } else {
      i++;
    }
  }
  if (idxNonZero > 1) {
    n = 0;
    c_i = a_size[1];
    for (k = 0; k < c_i; k++) {
      if (a_data[k] != 0.0) {
        n++;
      }
    }
    firflag = (n == 1);
  } else {
    firflag = true;
  }
  if (firflag) {
    islinphaseflag = determineiflinphase(b_data, b_size);
  } else {
    double absknxt2;
    int loop_ub;
    boolean_T errFlag;
    i = 0;
    exitg1 = false;
    while ((!exitg1) && (i < a_size[1])) {
      c_i = a_size[1] - i;
      if ((c_i < 1) || (c_i > a_size[1])) {
        rtDynamicBoundsError(c_i, 1, a_size[1], &b_emlrtBCI);
      }
      if (a_data[c_i - 1] == 0.0) {
        i++;
      } else {
        exitg1 = true;
      }
    }
    if (i == a_size[1]) {
      n_rtErrorWithMessageID(k_emlrtRTEI.fName, k_emlrtRTEI.lineNo);
    }
    c_i = a_size[1] - i;
    if (c_i < 1) {
      c_i = 0;
    } else if (c_i > a_size[1]) {
      rtDynamicBoundsError(c_i, 1, a_size[1], &r_emlrtBCI);
    }
    idxNonZero = 1;
    int exitg2;
    do {
      exitg2 = 0;
      if ((idxNonZero < 1) || (idxNonZero > c_i)) {
        rtDynamicBoundsError(idxNonZero, 1, c_i, &c_emlrtBCI);
      }
      if (a_data[idxNonZero - 1] == 0.0) {
        idxNonZero++;
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);
    if (idxNonZero > c_i) {
      i1 = 0;
      c_i = 0;
    } else {
      i1 = idxNonZero - 1;
      if (c_i < 1) {
        rtDynamicBoundsError(0, 1, 0, &q_emlrtBCI);
      }
    }
    loop_ub = c_i - i1;
    if (loop_ub < 1) {
      rtDynamicBoundsError(1, 1, loop_ub, &d_emlrtBCI);
    }
    absknxt2 = a_data[i1];
    for (c_i = 0; c_i < loop_ub; c_i++) {
      a2_data[c_i] = a_data[i1 + c_i] / absknxt2;
    }
    if (loop_ub == 1) {
      firflag = true;
    } else if (loop_ub == 2) {
      firflag = (fabs(a2_data[1]) < 1.0);
    } else {
      firflag = true;
      absknxt2 = fabs(a2_data[loop_ub - 1]);
      if (absknxt2 >= 1.0) {
        firflag = false;
      } else {
        double a2;
        boolean_T y;
        errFlag = (a2_data[0] == 0.0);
        a2 = a2_data[0];
        for (c_i = 0; c_i < loop_ub; c_i++) {
          temp_a1_data[c_i] = a2_data[c_i] / a2;
        }
        idxNonZero = loop_ub - 1;
        memset(&k_data[0], 0, (unsigned int)idxNonZero * sizeof(double));
        k_data[loop_ub - 2] = temp_a1_data[loop_ub - 1];
        memcpy(&a2_data[0], &temp_a1_data[0],
               (unsigned int)loop_ub * sizeof(double));
        memset(&errLevdown_data[0], 0,
               (unsigned int)(loop_ub - 1) * sizeof(boolean_T));
        for (k = 0; k <= loop_ub - 3; k++) {
          int iv[2];
          int b_loop_ub;
          i = loop_ub - k;
          if ((i < 1) || (i > loop_ub)) {
            rtDynamicBoundsError(i, 1, loop_ub, &e_emlrtBCI);
          }
          if ((i - 1 < 1) || (i - 1 > loop_ub - 1)) {
            rtDynamicBoundsError(i - 1, 1, loop_ub - 1, &f_emlrtBCI);
          }
          if ((i - 2 < 1) || (i - 2 > loop_ub - 1)) {
            rtDynamicBoundsError(i - 2, 1, loop_ub - 1, &g_emlrtBCI);
          }
          errLevdown_data[i - 3] = false;
          if (i < 2) {
            c_i = 0;
            i1 = 0;
          } else {
            c_i = 1;
            i1 = i;
          }
          iv[0] = 1;
          i2 = i1 - c_i;
          iv[1] = i2;
          indexShapeCheck(i, iv);
          if (i2 < 1) {
            rtDynamicBoundsError(i2, 1, i2, &h_emlrtBCI);
          }
          a2 = a2_data[i1 - 1];
          if (a2 == 1.0) {
            if (i - 2 > loop_ub - 1) {
              rtDynamicBoundsError(i - 2, 1, loop_ub - 1, &g_emlrtBCI);
            }
            errLevdown_data[i - 3] = true;
          }
          absknxt2 = fabs(a2);
          absknxt2 *= absknxt2;
          if (i2 - 1 < 1) {
            b_loop_ub = 0;
          } else {
            if ((i2 - 1 < 1) || (i2 - 1 > i2)) {
              rtDynamicBoundsError(i2 - 1, 1, i2, &n_emlrtBCI);
            }
            b_loop_ub = i2 - 1;
          }
          iv[0] = 1;
          iv[1] = b_loop_ub;
          indexShapeCheck(i2, iv);
          if (i2 - 1 < 1) {
            i1 = 0;
            n = 1;
            idxNonZero = -1;
          } else {
            if ((i2 - 1 < 1) || (i2 - 1 > i2)) {
              rtDynamicBoundsError(i2 - 1, 1, i2, &m_emlrtBCI);
            }
            i1 = i2 - 2;
            n = -1;
            idxNonZero = 0;
          }
          iv[0] = 1;
          idxNonZero = div_s32(idxNonZero - i1, n);
          iv[1] = idxNonZero + 1;
          indexShapeCheck(i2, iv);
          b_i = idxNonZero + 1;
          for (i2 = 0; i2 <= idxNonZero; i2++) {
            temp_a1_data[i2] = a2 * a2_data[(c_i + i1) + n * i2];
          }
          if ((b_loop_ub != idxNonZero + 1) &&
              ((b_loop_ub != 1) && (idxNonZero + 1 != 1))) {
            emlrtDimSizeImpxCheckR2021b(b_loop_ub, idxNonZero + 1, &emlrtECI);
          }
          if (i - 2 > loop_ub - 1) {
            rtDynamicBoundsError(i - 2, 1, loop_ub - 1, &i_emlrtBCI);
          }
          if (b_loop_ub == idxNonZero + 1) {
            idxNonZero = b_loop_ub + 1;
            acur_data[0] = 1.0;
            for (i1 = 0; i1 < b_loop_ub; i1++) {
              acur_data[i1 + 1] =
                  (a2_data[c_i + i1] - temp_a1_data[i1]) / (1.0 - absknxt2);
            }
          } else {
            idxNonZero = c_binary_expand_op(acur_data, a2_data, c_i, b_loop_ub,
                                            temp_a1_data, &b_i, absknxt2);
          }
          if (i - 1 < 1) {
            c_i = 0;
          } else {
            if ((i - 1 < 1) || (i - 1 > loop_ub)) {
              rtDynamicBoundsError(i - 1, 1, loop_ub, &l_emlrtBCI);
            }
            c_i = i - 1;
          }
          if (c_i != idxNonZero) {
            rtSizeEq1DError(c_i, idxNonZero, &b_emlrtECI);
          }
          if (idxNonZero - 1 >= 0) {
            memcpy(&a2_data[0], &acur_data[0],
                   (unsigned int)idxNonZero * sizeof(double));
          }
          if ((i - 1 < 1) || (i - 1 > loop_ub)) {
            rtDynamicBoundsError(i - 1, 1, loop_ub, &j_emlrtBCI);
          }
          if (i - 2 > loop_ub - 1) {
            rtDynamicBoundsError(i - 2, 1, loop_ub - 1, &k_emlrtBCI);
          }
          k_data[i - 3] = a2_data[i - 2];
        }
        y = false;
        idxNonZero = 1;
        exitg1 = false;
        while ((!exitg1) && (idxNonZero <= loop_ub - 1)) {
          if (errLevdown_data[idxNonZero - 1]) {
            y = true;
            exitg1 = true;
          } else {
            idxNonZero++;
          }
        }
        errFlag = (y || errFlag);
        if (errFlag) {
          firflag = false;
        } else {
          i = 0;
          exitg1 = false;
          while ((!exitg1) && (i <= loop_ub - 2)) {
            if (i + 1 > loop_ub - 1) {
              rtDynamicBoundsError(i + 1, 1, loop_ub - 1, &o_emlrtBCI);
            }
            if (rtIsNaN(k_data[i])) {
              firflag = false;
              exitg1 = true;
            } else {
              if (i + 1 > loop_ub - 1) {
                rtDynamicBoundsError(i + 1, 1, loop_ub - 1, &p_emlrtBCI);
              }
              if (fabs(k_data[i]) >= 1.0) {
                firflag = false;
                exitg1 = true;
              } else {
                i++;
              }
            }
          }
        }
      }
    }
    if (firflag) {
      islinphaseflag = false;
    } else {
      firflag = determineiflinphase(b_data, b_size);
      errFlag = determineiflinphase(a_data, a_size);
      islinphaseflag = (firflag && errFlag);
    }
  }
  return islinphaseflag;
}

/* End of code generation (islinphase.c) */
