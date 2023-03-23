/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * uavrt_tag_analyzer.c
 *
 * Code generation for function 'uavrt_tag_analyzer'
 *
 */

/* Include files */
#include "uavrt_tag_analyzer.h"
#include "abs.h"
#include "colon.h"
#include "combineVectorElements.h"
#include "decimate.h"
#include "diff.h"
#include "eml_int_forloop_overflow_check.h"
#include "factor.h"
#include "fft.h"
#include "fftshift.h"
#include "fileManager.h"
#include "fread.h"
#include "histcounts.h"
#include "ifWhileCond.h"
#include "indexShapeCheck.h"
#include "locateoutliers.h"
#include "mean.h"
#include "minOrMax.h"
#include "nullAssignment.h"
#include "rt_nonfinite.h"
#include "std.h"
#include "strcmp.h"
#include "uavrt_tag_analyzer_data.h"
#include "uavrt_tag_analyzer_emxutil.h"
#include "uavrt_tag_analyzer_initialize.h"
#include "uavrt_tag_analyzer_internal_types.h"
#include "uavrt_tag_analyzer_rtwutil.h"
#include "uavrt_tag_analyzer_types.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <stdio.h>

/* Function Declarations */
static void b_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void binary_expand_op(emxArray_creal_T *in1, const emxArray_real_T *in2,
                             int in3, int in4);

static void d_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

/* Function Definitions */
static void b_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  fprintf(stderr, "fopen(\'all\') is not supported for code generation.");
  fprintf(stderr, "\n");
  fprintf(stderr, "Error in %s (line %d)", aFcnName, aLineNum);
  fprintf(stderr, "\n");
  fflush(stderr);
  abort();
}

static void binary_expand_op(emxArray_creal_T *in1, const emxArray_real_T *in2,
                             int in3, int in4)
{
  emxArray_creal_T *b_in2;
  creal_T *b_in2_data;
  creal_T *in1_data;
  const double *in2_data;
  int i;
  int i1;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  in2_data = in2->data;
  in1_data = in1->data;
  emxInit_creal_T(&b_in2);
  i = div_s32(in4, in3) + 1;
  if (in1->size[0] == 1) {
    loop_ub = i;
  } else {
    loop_ub = in1->size[0];
  }
  i1 = b_in2->size[0];
  b_in2->size[0] = loop_ub;
  emxEnsureCapacity_creal_T(b_in2, i1);
  b_in2_data = b_in2->data;
  stride_0_0 = (i != 1);
  stride_1_0 = (in1->size[0] != 1);
  for (i = 0; i < loop_ub; i++) {
    i1 = i * stride_1_0;
    b_in2_data[i].re = in2_data[in3 * (i * stride_0_0)] + in1_data[i1].re;
    b_in2_data[i].im = in1_data[i1].im;
  }
  i = in1->size[0];
  in1->size[0] = b_in2->size[0];
  emxEnsureCapacity_creal_T(in1, i);
  in1_data = in1->data;
  loop_ub = b_in2->size[0];
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] = b_in2_data[i];
  }
  emxFree_creal_T(&b_in2);
}

static void d_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  fprintf(stderr, "NaN values cannot be converted to logicals.");
  fprintf(stderr, "\n");
  fprintf(stderr, "Error in %s (line %d)", aFcnName, aLineNum);
  fprintf(stderr, "\n");
  fflush(stderr);
  abort();
}

void uavrt_tag_analyzer(double FsRawInput, double tp, double centerFreqMHz,
                        const char filePath_data[], const int filePath_size[2])
{
  static rtBoundsCheckInfo b_emlrtBCI = {
      -1,                   /* iFirst */
      -1,                   /* iLast */
      82,                   /* lineNo */
      17,                   /* colNo */
      "dataThresholded",    /* aName */
      "uavrt_tag_analyzer", /* fName */
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_tag_analyzer/uavrt_tag_analyzer.m", /* pName */
      0                                                          /* checkKind */
  };
  static rtBoundsCheckInfo c_emlrtBCI = {
      -1,                   /* iFirst */
      -1,                   /* iLast */
      83,                   /* lineNo */
      17,                   /* colNo */
      "dataThresholded",    /* aName */
      "uavrt_tag_analyzer", /* fName */
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_tag_analyzer/uavrt_tag_analyzer.m", /* pName */
      0                                                          /* checkKind */
  };
  static rtBoundsCheckInfo d_emlrtBCI = {
      -1,                   /* iFirst */
      -1,                   /* iLast */
      91,                   /* lineNo */
      13,                   /* colNo */
      "t",                  /* aName */
      "uavrt_tag_analyzer", /* fName */
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_tag_analyzer/uavrt_tag_analyzer.m", /* pName */
      0                                                          /* checkKind */
  };
  static rtBoundsCheckInfo e_emlrtBCI = {
      -1,                   /* iFirst */
      -1,                   /* iLast */
      95,                   /* lineNo */
      17,                   /* colNo */
      "t",                  /* aName */
      "uavrt_tag_analyzer", /* fName */
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_tag_analyzer/uavrt_tag_analyzer.m", /* pName */
      0                                                          /* checkKind */
  };
  static rtBoundsCheckInfo emlrtBCI = {
      -1,                     /* iFirst */
      -1,                     /* iLast */
      64,                     /* lineNo */
      66,                     /* colNo */
      "decimationFactorList", /* aName */
      "uavrt_tag_analyzer",   /* fName */
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_tag_analyzer/uavrt_tag_analyzer.m", /* pName */
      0                                                          /* checkKind */
  };
  static rtBoundsCheckInfo f_emlrtBCI = {
      -1,                   /* iFirst */
      -1,                   /* iLast */
      96,                   /* lineNo */
      15,                   /* colNo */
      "t",                  /* aName */
      "uavrt_tag_analyzer", /* fName */
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_tag_analyzer/uavrt_tag_analyzer.m", /* pName */
      0                                                          /* checkKind */
  };
  static rtBoundsCheckInfo g_emlrtBCI = {
      -1,                   /* iFirst */
      -1,                   /* iLast */
      99,                   /* lineNo */
      40,                   /* colNo */
      "tPulseStart",        /* aName */
      "uavrt_tag_analyzer", /* fName */
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_tag_analyzer/uavrt_tag_analyzer.m", /* pName */
      0                                                          /* checkKind */
  };
  static rtBoundsCheckInfo h_emlrtBCI = {
      -1,                   /* iFirst */
      -1,                   /* iLast */
      101,                  /* lineNo */
      37,                   /* colNo */
      "tPulseEnd",          /* aName */
      "uavrt_tag_analyzer", /* fName */
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_tag_analyzer/uavrt_tag_analyzer.m", /* pName */
      0                                                          /* checkKind */
  };
  static rtBoundsCheckInfo i_emlrtBCI = {
      -1,                   /* iFirst */
      -1,                   /* iLast */
      102,                  /* lineNo */
      50,                   /* colNo */
      "tPulseStart",        /* aName */
      "uavrt_tag_analyzer", /* fName */
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_tag_analyzer/uavrt_tag_analyzer.m", /* pName */
      0                                                          /* checkKind */
  };
  static rtBoundsCheckInfo j_emlrtBCI = {
      -1,                   /* iFirst */
      -1,                   /* iLast */
      104,                  /* lineNo */
      28,                   /* colNo */
      "pulseDurRecord",     /* aName */
      "uavrt_tag_analyzer", /* fName */
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_tag_analyzer/uavrt_tag_analyzer.m", /* pName */
      0                                                          /* checkKind */
  };
  static rtBoundsCheckInfo k_emlrtBCI = {
      -1,                   /* iFirst */
      -1,                   /* iLast */
      106,                  /* lineNo */
      28,                   /* colNo */
      "pulseDurRecord",     /* aName */
      "uavrt_tag_analyzer", /* fName */
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_tag_analyzer/uavrt_tag_analyzer.m", /* pName */
      0                                                          /* checkKind */
  };
  static rtBoundsCheckInfo l_emlrtBCI = {
      -1,                   /* iFirst */
      -1,                   /* iLast */
      109,                  /* lineNo */
      24,                   /* colNo */
      "pulseDurRecord",     /* aName */
      "uavrt_tag_analyzer", /* fName */
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_tag_analyzer/uavrt_tag_analyzer.m", /* pName */
      0                                                          /* checkKind */
  };
  static rtBoundsCheckInfo m_emlrtBCI = {
      -1,                   /* iFirst */
      -1,                   /* iLast */
      128,                  /* lineNo */
      27,                   /* colNo */
      "dataDecimated",      /* aName */
      "uavrt_tag_analyzer", /* fName */
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_tag_analyzer/uavrt_tag_analyzer.m", /* pName */
      0                                                          /* checkKind */
  };
  static rtBoundsCheckInfo n_emlrtBCI = {
      -1,                   /* iFirst */
      -1,                   /* iLast */
      134,                  /* lineNo */
      14,                   /* colNo */
      "f",                  /* aName */
      "uavrt_tag_analyzer", /* fName */
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_tag_analyzer/uavrt_tag_analyzer.m", /* pName */
      0                                                          /* checkKind */
  };
  static rtBoundsCheckInfo o_emlrtBCI = {
      -1,                   /* iFirst */
      -1,                   /* iLast */
      55,                   /* lineNo */
      23,                   /* colNo */
      "dataRaw",            /* aName */
      "uavrt_tag_analyzer", /* fName */
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_tag_analyzer/uavrt_tag_analyzer.m", /* pName */
      0                                                          /* checkKind */
  };
  static rtBoundsCheckInfo p_emlrtBCI = {
      -1,                   /* iFirst */
      -1,                   /* iLast */
      55,                   /* lineNo */
      27,                   /* colNo */
      "dataRaw",            /* aName */
      "uavrt_tag_analyzer", /* fName */
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_tag_analyzer/uavrt_tag_analyzer.m", /* pName */
      0                                                          /* checkKind */
  };
  static rtDoubleCheckInfo b_emlrtDCI = {
      51,                  /* lineNo */
      "uavrt_tag_analyzer" /* fName */
  };
  static rtEqualityCheckInfo emlrtECI = {
      1,                    /* nDims */
      55,                   /* lineNo */
      15,                   /* colNo */
      "uavrt_tag_analyzer", /* fName */
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_tag_analyzer/uavrt_tag_analyzer.m" /* pName */
  };
  static rtRunTimeErrorInfo k_emlrtRTEI = {
      37,     /* lineNo */
      "fopen" /* fName */
  };
  static rtRunTimeErrorInfo l_emlrtRTEI = {
      81,        /* lineNo */
      "eml_find" /* fName */
  };
  static rtRunTimeErrorInfo m_emlrtRTEI = {
      392,                 /* lineNo */
      "find_first_indices" /* fName */
  };
  static rtRunTimeErrorInfo n_emlrtRTEI = {
      13,              /* lineNo */
      "toLogicalCheck" /* fName */
  };
  emxArray_boolean_T *outLoc;
  emxArray_boolean_T *r4;
  emxArray_creal_T *b_dataComplex;
  emxArray_creal_T *dataComplex;
  emxArray_int32_T *nz;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_int32_T *r2;
  emxArray_int32_T *r3;
  emxArray_real_T *dataRaw;
  emxArray_real_T *dt;
  emxArray_real_T *pulseDurRecord;
  emxArray_real_T *t;
  emxArray_real_T *transitions;
  creal_T ex;
  creal_T *b_dataComplex_data;
  creal_T *dataComplex_data;
  double edges_data[11];
  double a__1_data[10];
  double pulseFreqMHz;
  double *dataRaw_data;
  double *dt_data;
  double *pulseDurRecord_data;
  double *t_data;
  double *transitions_data;
  unsigned int decimationFactorList_data[31];
  int b_end_tmp;
  int b_i;
  int fid;
  int i;
  int i1;
  int k;
  unsigned int u;
  int *nz_data;
  int *r5;
  boolean_T *outLoc_data;
  if (!isInitialized_uavrt_tag_analyzer) {
    uavrt_tag_analyzer_initialize();
  }
  /* UNTITLED3 Summary of this function goes here */
  /*    Detailed explanation goes here */
  pulseFreqMHz = rt_roundd_snf(FsRawInput);
  if (pulseFreqMHz < 4.294967296E+9) {
    if (pulseFreqMHz >= 0.0) {
      u = (unsigned int)pulseFreqMHz;
    } else {
      u = 0U;
    }
  } else if (pulseFreqMHz >= 4.294967296E+9) {
    u = MAX_uint32_T;
  } else {
    u = 0U;
  }
  /* Debugging */
  /*  fprintf('FsRawInput %f \n',FsRawInput) */
  /*  fprintf('FsRaw %u \n',FsRaw) */
  /*  fprintf('tp %f \n',tp) */
  /*  fprintf('centerFreqMHz %f \n',centerFreqMHz) */
  /*  fprintf('filePath %s \n',filePath) */
  /*  */
  emxInit_real_T(&dataRaw, 1);
  emxInit_real_T(&t, 2);
  emxInit_real_T(&transitions, 1);
  emxInit_real_T(&dt, 2);
  emxInit_real_T(&pulseDurRecord, 2);
  emxInit_creal_T(&dataComplex);
  emxInit_int32_T(&r, 1);
  emxInit_int32_T(&r1, 1);
  emxInit_int32_T(&r2, 1);
  emxInit_boolean_T(&outLoc, 2);
  emxInit_int32_T(&nz, 2);
  emxInit_int32_T(&r3, 2);
  emxInit_boolean_T(&r4, 1);
  emxInit_creal_T(&b_dataComplex);
  if (u - u / 10000U * 10000U != 0U) {
    printf("UAV-RT: Sample rate must be divisible by 10000.\n");
    fflush(stdout);
  } else if (tp <= 0.0) {
    printf("UAV-RT: Pulse duration must be greater than 0.\n");
    fflush(stdout);
  } else if (u <= 0U) {
    printf("UAV-RT: Sample rate must be greater than 0.\n");
    fflush(stdout);
  } else if (rt_roundd_snf(1.0 / (double)u) >= tp) {
    printf("UAV-RT: Sample period (1/Fs) be greater than pulse duration.\n");
    fflush(stdout);
  } else {
    printf("Loading data...\n");
    fflush(stdout);
    if (b_strcmp(filePath_data, filePath_size)) {
      b_rtErrorWithMessageID(k_emlrtRTEI.fName, k_emlrtRTEI.lineNo);
    } else {
      signed char fileid;
      fileid = cfopen(filePath_data, filePath_size);
      fid = fileid;
    }
    if (fid != -1) {
      double ai;
      double b_validatedHoleFilling_idx_0;
      double c_validatedHoleFilling_idx_0;
      double pulseDur_data;
      double validatedHoleFilling_idx_0;
      double y;
      int decimationFactorList_size[2];
      int end_tmp;
      int ii_data;
      b_fread(fid, dataRaw);
      dataRaw_data = dataRaw->data;
      printf("Done.\n");
      fflush(stdout);
      i = r4->size[0];
      r4->size[0] = dataRaw->size[0];
      emxEnsureCapacity_boolean_T(r4, i);
      outLoc_data = r4->data;
      k = dataRaw->size[0];
      for (i = 0; i < k; i++) {
        pulseFreqMHz = dataRaw_data[i];
        if (rtIsNaN(pulseFreqMHz) || rtIsInf(pulseFreqMHz)) {
          pulseDur_data = rtNaN;
        } else if (pulseFreqMHz == 0.0) {
          pulseDur_data = 0.0;
        } else {
          pulseDur_data = fmod(pulseFreqMHz, 2.0);
          if (pulseDur_data == 0.0) {
            pulseDur_data = 0.0;
          } else if (pulseFreqMHz < 0.0) {
            pulseDur_data += 2.0;
          }
        }
        outLoc_data[i] = (pulseDur_data != 0.0);
      }
      if (ifWhileCond(r4)) {
        nullAssignment(dataRaw, dataRaw->size[0]);
        dataRaw_data = dataRaw->data;
      }
      pulseFreqMHz = (double)dataRaw->size[0] / 2.0;
      if (pulseFreqMHz != floor(pulseFreqMHz)) {
        rtIntegerError(pulseFreqMHz, &b_emlrtDCI);
      }
      if (dataRaw->size[0] - 1 < 1) {
        i = 1;
        i1 = -1;
      } else {
        if (dataRaw->size[0] < 1) {
          rtDynamicBoundsError(1, 1, dataRaw->size[0], &o_emlrtBCI);
        }
        i = 2;
        if ((dataRaw->size[0] - 1 < 1) ||
            (dataRaw->size[0] - 1 > dataRaw->size[0])) {
          rtDynamicBoundsError(dataRaw->size[0] - 1, 1, dataRaw->size[0],
                               &p_emlrtBCI);
        }
        i1 = dataRaw->size[0] - 2;
      }
      decimationFactorList_size[0] = 1;
      k = div_s32(i1, i);
      decimationFactorList_size[1] = k + 1;
      indexShapeCheck(dataRaw->size[0], decimationFactorList_size);
      if (dataRaw->size[0] < 2) {
        fid = 1;
        end_tmp = 1;
        b_end_tmp = 0;
      } else {
        fid = 2;
        end_tmp = 2;
        b_end_tmp = dataRaw->size[0];
      }
      decimationFactorList_size[0] = 1;
      ii_data = div_s32(b_end_tmp - fid, end_tmp);
      decimationFactorList_size[1] = ii_data + 1;
      indexShapeCheck(dataRaw->size[0], decimationFactorList_size);
      b_end_tmp = dataComplex->size[0];
      dataComplex->size[0] = ii_data + 1;
      emxEnsureCapacity_creal_T(dataComplex, b_end_tmp);
      dataComplex_data = dataComplex->data;
      for (b_end_tmp = 0; b_end_tmp <= ii_data; b_end_tmp++) {
        pulseFreqMHz = dataRaw_data[(fid + end_tmp * b_end_tmp) - 1];
        dataComplex_data[b_end_tmp].re = pulseFreqMHz * 0.0;
        dataComplex_data[b_end_tmp].im = pulseFreqMHz;
      }
      if ((k + 1 != dataComplex->size[0]) &&
          ((k + 1 != 1) && (dataComplex->size[0] != 1))) {
        emlrtDimSizeImpxCheckR2021b(k + 1, dataComplex->size[0], &emlrtECI);
      }
      if (k + 1 == dataComplex->size[0]) {
        i1 = dataComplex->size[0];
        dataComplex->size[0] = k + 1;
        emxEnsureCapacity_creal_T(dataComplex, i1);
        dataComplex_data = dataComplex->data;
        for (i1 = 0; i1 <= k; i1++) {
          dataComplex_data[i1].re += dataRaw_data[i * i1];
        }
      } else {
        binary_expand_op(dataComplex, dataRaw, i, i1);
        dataComplex_data = dataComplex->data;
      }
      factor(u / 10000U, decimationFactorList_data, decimationFactorList_size);
      i = decimationFactorList_size[1];
      for (b_i = 0; b_i < i; b_i++) {
        printf("Decimating data...\n");
        fflush(stdout);
        if (b_i + 1 > decimationFactorList_size[1]) {
          rtDynamicBoundsError(b_i + 1, 1, decimationFactorList_size[1],
                               &emlrtBCI);
        }
        i1 = b_dataComplex->size[0];
        b_dataComplex->size[0] = dataComplex->size[0];
        emxEnsureCapacity_creal_T(b_dataComplex, i1);
        b_dataComplex_data = b_dataComplex->data;
        k = dataComplex->size[0] - 1;
        for (i1 = 0; i1 <= k; i1++) {
          b_dataComplex_data[i1] = dataComplex_data[i1];
        }
        decimate(b_dataComplex, decimationFactorList_data[b_i], dataComplex);
        dataComplex_data = dataComplex->data;
      }
      /* Level for max out at 1; */
      b_abs(dataComplex, dataRaw);
      y = b_maximum(dataRaw);
      k = dataComplex->size[0];
      for (i = 0; i < k; i++) {
        pulseFreqMHz = dataComplex_data[i].re;
        ai = dataComplex_data[i].im;
        if (ai == 0.0) {
          pulseDur_data = pulseFreqMHz / y;
          pulseFreqMHz = 0.0;
        } else if (pulseFreqMHz == 0.0) {
          pulseDur_data = 0.0;
          pulseFreqMHz = ai / y;
        } else {
          pulseDur_data = pulseFreqMHz / y;
          pulseFreqMHz = ai / y;
        }
        dataComplex_data[i].re = pulseDur_data;
        dataComplex_data[i].im = pulseFreqMHz;
      }
      int edges_size[2];
      printf("Done.\n");
      fflush(stdout);
      /*  n_pulse = Fs * tp; */
      /*  rectWind = rectwin(n_pulse); */
      /*  n_overlap = floor(0.5 * n_pulse); */
      /*  fprintf('Computing STFT...\n') */
      /*  [s,f,t] =
       * stft(dataDecimated,Fs,Window=rectWind,OverlapLength=n_overlap,FFTLength=n_pulse);
       */
      /*  fprintf('Done.\n') */
      b_abs(dataComplex, dataRaw);
      dataRaw_data = dataRaw->data;
      histcounts(dataRaw, a__1_data, decimationFactorList_size, edges_data,
                 edges_size);
      b_end_tmp = dataRaw->size[0] - 1;
      for (b_i = 0; b_i <= b_end_tmp; b_i++) {
        if (dataRaw_data[b_i] >= edges_data[7]) {
          if (b_i > b_end_tmp) {
            rtDynamicBoundsError(b_i, 0, b_end_tmp, &b_emlrtBCI);
          }
          dataRaw_data[b_i] = 1.0;
        }
      }
      for (b_i = 0; b_i <= b_end_tmp; b_i++) {
        if (dataRaw_data[b_i] < edges_data[7]) {
          if (b_i > b_end_tmp) {
            rtDynamicBoundsError(b_i, 0, b_end_tmp, &c_emlrtBCI);
          }
          dataRaw_data[b_i] = 0.0;
        }
      }
      if (dataComplex->size[0] - 1 < 0) {
        t->size[1] = 0;
      } else {
        i = t->size[0] * t->size[1];
        t->size[0] = 1;
        t->size[1] = dataComplex->size[0];
        emxEnsureCapacity_real_T(t, i);
        t_data = t->data;
        k = dataComplex->size[0] - 1;
        for (i = 0; i <= k; i++) {
          t_data[i] = i;
        }
      }
      i = t->size[0] * t->size[1];
      t->size[0] = 1;
      emxEnsureCapacity_real_T(t, i);
      t_data = t->data;
      ii_data = t->size[1] - 1;
      for (i = 0; i <= ii_data; i++) {
        t_data[i] *= 0.0001;
      }
      /* figure;  */
      /* plot(t, dataThresholded) */
      /* hold on; plot(t,dataAbsDecimated/max(dataAbsDecimated)) */
      diff(dataRaw, transitions);
      transitions_data = transitions->data;
      end_tmp = transitions->size[0] - 1;
      fid = 0;
      for (b_i = 0; b_i <= end_tmp; b_i++) {
        if (transitions_data[b_i] == 1.0) {
          fid++;
        }
      }
      i = r2->size[0];
      r2->size[0] = fid;
      emxEnsureCapacity_int32_T(r2, i);
      r5 = r2->data;
      fid = 0;
      for (b_i = 0; b_i <= end_tmp; b_i++) {
        if (transitions_data[b_i] == 1.0) {
          r5[fid] = b_i;
          fid++;
        }
      }
      i = pulseDurRecord->size[0] * pulseDurRecord->size[1];
      pulseDurRecord->size[0] = 1;
      pulseDurRecord->size[1] = r2->size[0];
      emxEnsureCapacity_real_T(pulseDurRecord, i);
      pulseDurRecord_data = pulseDurRecord->data;
      k = r2->size[0];
      for (i = 0; i < k; i++) {
        if (r5[i] > ii_data) {
          rtDynamicBoundsError(r5[i], 0, ii_data, &d_emlrtBCI);
        }
        pulseDurRecord_data[i] = t_data[r5[i]];
      }
      b_diff(pulseDurRecord, dt);
      dt_data = dt->data;
      /* dtEnd = diff(t(transitions == -1)); */
      /* dtMode = mode(round(dtStart*100)/100); */
      k = r2->size[0];
      for (i = 0; i < k; i++) {
        if (r5[i] > ii_data) {
          rtDynamicBoundsError(r5[i], 0, ii_data, &e_emlrtBCI);
        }
      }
      fid = 0;
      for (b_i = 0; b_i <= end_tmp; b_i++) {
        if (transitions_data[b_i] == -1.0) {
          fid++;
        }
      }
      i = r->size[0];
      r->size[0] = fid;
      emxEnsureCapacity_int32_T(r, i);
      nz_data = r->data;
      fid = 0;
      for (b_i = 0; b_i <= end_tmp; b_i++) {
        if (transitions_data[b_i] == -1.0) {
          nz_data[fid] = b_i;
          fid++;
        }
      }
      k = r->size[0];
      for (i = 0; i < k; i++) {
        if (nz_data[i] > ii_data) {
          rtDynamicBoundsError(nz_data[i], 0, ii_data, &f_emlrtBCI);
        }
      }
      i = pulseDurRecord->size[0] * pulseDurRecord->size[1];
      pulseDurRecord->size[0] = 1;
      pulseDurRecord->size[1] = r2->size[0];
      emxEnsureCapacity_real_T(pulseDurRecord, i);
      pulseDurRecord_data = pulseDurRecord->data;
      k = r2->size[0];
      for (i = 0; i < k; i++) {
        pulseDurRecord_data[i] = 0.0;
      }
      i = r2->size[0];
      for (b_i = 0; b_i < i; b_i++) {
        boolean_T exitg1;
        if (b_i + 1 > r2->size[0]) {
          rtDynamicBoundsError(b_i + 1, 1, r2->size[0], &g_emlrtBCI);
        }
        pulseFreqMHz = t_data[r5[b_i]];
        i1 = outLoc->size[0] * outLoc->size[1];
        outLoc->size[0] = 1;
        k = r->size[0];
        outLoc->size[1] = r->size[0];
        emxEnsureCapacity_boolean_T(outLoc, i1);
        outLoc_data = outLoc->data;
        for (i1 = 0; i1 < k; i1++) {
          outLoc_data[i1] = (t_data[nz_data[i1]] > pulseFreqMHz);
        }
        k = (outLoc->size[1] >= 1);
        if (k > outLoc->size[1]) {
          rtErrorWithMessageID(l_emlrtRTEI.fName, l_emlrtRTEI.lineNo);
        }
        fid = 0;
        if (outLoc->size[1] > 2147483646) {
          check_forloop_overflow_error();
        }
        end_tmp = 0;
        exitg1 = false;
        while ((!exitg1) && (end_tmp <= outLoc->size[1] - 1)) {
          if (outLoc_data[end_tmp]) {
            fid = 1;
            ii_data = end_tmp + 1;
            exitg1 = true;
          } else {
            end_tmp++;
          }
        }
        if (fid > k) {
          rtErrorWithMessageID(m_emlrtRTEI.fName, m_emlrtRTEI.lineNo);
        }
        if (k == 1) {
          if (fid == 0) {
            k = 0;
          }
        } else {
          k = (fid >= 1);
        }
        if (k != 0) {
          boolean_T b_y;
          boolean_T guard1 = false;
          boolean_T x_data;
          if (ii_data > r->size[0]) {
            rtDynamicBoundsError(ii_data, 1, r->size[0], &h_emlrtBCI);
          }
          if (b_i + 1 > r2->size[0]) {
            rtDynamicBoundsError(b_i + 1, 1, r2->size[0], &i_emlrtBCI);
          }
          pulseDur_data = t_data[nz_data[ii_data - 1]] - pulseFreqMHz;
          pulseFreqMHz = 2.0 * tp;
          x_data = (pulseDur_data <= pulseFreqMHz);
          b_y = (int)x_data;
          guard1 = false;
          if (b_y) {
            pulseFreqMHz = 0.5 * tp;
            x_data = (pulseDur_data >= pulseFreqMHz);
            b_y = (int)x_data;
            if (b_y) {
              /* Filter for weird transitions that cause huge or small pulse
               * durations.  */
              if (b_i + 1 > pulseDurRecord->size[1]) {
                rtDynamicBoundsError(b_i + 1, 1, pulseDurRecord->size[1],
                                     &j_emlrtBCI);
              }
              pulseDurRecord_data[b_i] = pulseDur_data;
            } else {
              guard1 = true;
            }
          } else {
            guard1 = true;
          }
          if (guard1) {
            if (b_i + 1 > pulseDurRecord->size[1]) {
              rtDynamicBoundsError(b_i + 1, 1, pulseDurRecord->size[1],
                                   &k_emlrtBCI);
            }
            pulseDurRecord_data[b_i] = rtNaN;
          }
        } else {
          if (b_i + 1 > pulseDurRecord->size[1]) {
            rtDynamicBoundsError(b_i + 1, 1, pulseDurRecord->size[1],
                                 &l_emlrtBCI);
          }
          pulseDurRecord_data[b_i] = rtNaN;
        }
      }
      i = outLoc->size[0] * outLoc->size[1];
      outLoc->size[0] = 1;
      outLoc->size[1] = pulseDurRecord->size[1];
      emxEnsureCapacity_boolean_T(outLoc, i);
      outLoc_data = outLoc->data;
      k = pulseDurRecord->size[1];
      for (i = 0; i < k; i++) {
        outLoc_data[i] = rtIsNaN(pulseDurRecord_data[i]);
      }
      b_nullAssignment(pulseDurRecord, outLoc);
      /* This was cutting out points that should be included. The pulse duration
       */
      /* check in the for loop should accomplish filtering out really large tp
       */
      /* values */
      /* pulseDurRecordClean = rmoutliers(pulseDurRecord,'median'); */
      y = mean(pulseDurRecord);
      validatedHoleFilling_idx_0 = b_std(pulseDurRecord);
      locateoutliers(dt, outLoc);
      combineVectorElements(outLoc, nz);
      nz_data = nz->data;
      end_tmp = nz->size[1] - 1;
      fid = 0;
      for (b_i = 0; b_i <= end_tmp; b_i++) {
        if (nz_data[b_i] < 1) {
          fid++;
        }
      }
      i = r3->size[0] * r3->size[1];
      r3->size[0] = 1;
      r3->size[1] = fid;
      emxEnsureCapacity_int32_T(r3, i);
      r5 = r3->data;
      fid = 0;
      for (b_i = 0; b_i <= end_tmp; b_i++) {
        if (nz_data[b_i] < 1) {
          r5[fid] = b_i;
          fid++;
        }
      }
      i = t->size[0] * t->size[1];
      t->size[0] = 1;
      t->size[1] = r3->size[1];
      emxEnsureCapacity_real_T(t, i);
      t_data = t->data;
      k = r3->size[1];
      for (i = 0; i < k; i++) {
        t_data[i] = dt_data[r5[i]];
      }
      b_validatedHoleFilling_idx_0 = b_std(t);
      c_validatedHoleFilling_idx_0 = mean(t);
      i = dataRaw->size[0];
      for (k = 0; k < i; k++) {
        if (rtIsNaN(dataRaw_data[k])) {
          d_rtErrorWithMessageID(n_emlrtRTEI.fName, n_emlrtRTEI.lineNo);
        }
      }
      fid = 0;
      for (b_i = 0; b_i <= b_end_tmp; b_i++) {
        if (dataRaw_data[b_i] != 0.0) {
          fid++;
        }
      }
      i = r1->size[0];
      r1->size[0] = fid;
      emxEnsureCapacity_int32_T(r1, i);
      r5 = r1->data;
      fid = 0;
      for (b_i = 0; b_i <= b_end_tmp; b_i++) {
        if (dataRaw_data[b_i] != 0.0) {
          r5[fid] = b_i;
          fid++;
        }
      }
      k = r1->size[0];
      for (i = 0; i < k; i++) {
        if (r5[i] > dataComplex->size[0] - 1) {
          rtDynamicBoundsError(r5[i], 0, dataComplex->size[0] - 1, &m_emlrtBCI);
        }
      }
      i = b_dataComplex->size[0];
      b_dataComplex->size[0] = r1->size[0];
      emxEnsureCapacity_creal_T(b_dataComplex, i);
      b_dataComplex_data = b_dataComplex->data;
      k = r1->size[0];
      for (i = 0; i < k; i++) {
        b_dataComplex_data[i] = dataComplex_data[r5[i]];
      }
      c_fft(b_dataComplex, dataComplex);
      fftshift(dataComplex);
      fid = c_maximum(dataComplex, &ex);
      pulseDur_data = -(double)r1->size[0] / 2.0;
      ai = (double)r1->size[0] / 2.0 - 1.0;
      if (ai < pulseDur_data) {
        t->size[1] = 0;
      } else if (floor(pulseDur_data) == pulseDur_data) {
        i = t->size[0] * t->size[1];
        t->size[0] = 1;
        k = (int)(ai - pulseDur_data);
        t->size[1] = k + 1;
        emxEnsureCapacity_real_T(t, i);
        t_data = t->data;
        for (i = 0; i <= k; i++) {
          t_data[i] = pulseDur_data + (double)i;
        }
      } else {
        eml_float_colon(pulseDur_data, ai, t);
      }
      i = t->size[0] * t->size[1];
      t->size[0] = 1;
      emxEnsureCapacity_real_T(t, i);
      t_data = t->data;
      k = t->size[1] - 1;
      for (i = 0; i <= k; i++) {
        t_data[i] = t_data[i] / (double)r1->size[0] * 10000.0;
      }
      if ((fid < 1) || (fid > t->size[1])) {
        rtDynamicBoundsError(fid, 1, t->size[1], &n_emlrtBCI);
      }
      pulseFreqMHz = centerFreqMHz + t_data[fid - 1] / 1.0E+6;
      printf("---------TAG REPORT---------\n");
      fflush(stdout);
      printf("Radio Frequency:       %.6f MHz\n", centerFreqMHz);
      fflush(stdout);
      printf("Pulse Frequency:       %.6f MHz\n", pulseFreqMHz);
      fflush(stdout);
      printf("Frequency Deviation:   %.6f Hz\n",
             (pulseFreqMHz - centerFreqMHz) * 1.0E+6);
      fflush(stdout);
      printf("Interpulse Time:       %.6f s\n", c_validatedHoleFilling_idx_0);
      fflush(stdout);
      printf("Interpulse Time Stdev: %.6f s\n", b_validatedHoleFilling_idx_0);
      fflush(stdout);
      printf("Pulse Mean Duration:   %.6f s\n", y);
      fflush(stdout);
      printf("Pulse Duration Stdev:  %.6f s\n", validatedHoleFilling_idx_0);
      fflush(stdout);
      printf("----------------------------\n");
      fflush(stdout);
      /*  if ~isdeployed */
      /*      first5SecInds = 1:(5*Fs); */
      /*      sound(real(dataDecimated(first5SecInds)),Fs) */
      /*  end */
    } else {
      printf("UAV-RT: Error opening file at path provided.\n");
      fflush(stdout);
    }
  }
  emxFree_creal_T(&b_dataComplex);
  emxFree_boolean_T(&r4);
  emxFree_int32_T(&r3);
  emxFree_int32_T(&nz);
  emxFree_boolean_T(&outLoc);
  emxFree_int32_T(&r2);
  emxFree_int32_T(&r1);
  emxFree_int32_T(&r);
  emxFree_creal_T(&dataComplex);
  emxFree_real_T(&pulseDurRecord);
  emxFree_real_T(&dt);
  emxFree_real_T(&transitions);
  emxFree_real_T(&t);
  emxFree_real_T(&dataRaw);
}

/* End of code generation (uavrt_tag_analyzer.c) */
