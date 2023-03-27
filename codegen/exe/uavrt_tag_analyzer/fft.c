/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * fft.c
 *
 * Code generation for function 'fft'
 *
 */

/* Include files */
#include "fft.h"
#include "FFTImplementationCallback.h"
#include "eml_int_forloop_overflow_check.h"
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
static void m_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

/* Function Definitions */
static void m_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  fprintf(stderr, "FFT length must be a nonnegative integer scalar.");
  fprintf(stderr, "\n");
  fprintf(stderr, "Error in %s (line %d)", aFcnName, aLineNum);
  fprintf(stderr, "\n");
  fflush(stderr);
  abort();
}

void b_fft(const double x_data[], const int x_size[2], double varargin_1,
           creal_T y_data[], int y_size[2])
{
  static rtRunTimeErrorInfo k_emlrtRTEI = {
      48,   /* lineNo */
      "fft" /* fName */
  };
  creal_T b_y_data[77];
  creal_T yCol_data[77];
  double costab_data[155];
  double sintab_data[155];
  double sintabinv_data[155];
  int N2blue;
  int nRows;
  if (!(varargin_1 == floor(varargin_1))) {
    m_rtErrorWithMessageID(k_emlrtRTEI.fName, k_emlrtRTEI.lineNo);
  }
  if ((x_size[1] == 0) || ((int)varargin_1 == 0)) {
    nRows = (int)varargin_1;
    N2blue = (int)varargin_1;
    if (nRows - 1 >= 0) {
      memset(&b_y_data[0], 0, (unsigned int)nRows * sizeof(creal_T));
    }
  } else {
    int costab_size[2];
    int sintab_size[2];
    int sintabinv_size[2];
    boolean_T useRadix2;
    useRadix2 = (((int)varargin_1 > 0) &&
                 (((int)varargin_1 & ((int)varargin_1 - 1)) == 0));
    N2blue = FFTImplementationCallback_get_algo_sizes((int)varargin_1,
                                                      useRadix2, &nRows);
    FFTImplementationCallback_generate_twiddle_tables(
        nRows, useRadix2, costab_data, costab_size, sintab_data, sintab_size,
        sintabinv_data, sintabinv_size);
    if (useRadix2) {
      FFTImplementationCallback_r2br_r2dit_trig(
          x_data, x_size[1], (int)varargin_1, costab_data, costab_size,
          sintab_data, yCol_data);
    } else {
      FFTImplementationCallback_dobluesteinfft(
          x_data, x_size[1], N2blue, (int)varargin_1, costab_data, costab_size,
          sintab_data, sintab_size, sintabinv_data, sintabinv_size, yCol_data);
    }
    nRows = (int)varargin_1;
    N2blue = (int)varargin_1;
    if (nRows - 1 >= 0) {
      memcpy(&b_y_data[0], &yCol_data[0],
             (unsigned int)nRows * sizeof(creal_T));
    }
  }
  y_size[0] = 1;
  y_size[1] = N2blue;
  if (N2blue - 1 >= 0) {
    memcpy(&y_data[0], &b_y_data[0], (unsigned int)N2blue * sizeof(creal_T));
  }
}

void c_fft(const emxArray_creal_T *x, emxArray_creal_T *y)
{
  static rtRunTimeErrorInfo k_emlrtRTEI = {
      37,   /* lineNo */
      "fft" /* fName */
  };
  emxArray_creal_T *fv;
  emxArray_creal_T *fy;
  emxArray_creal_T *wwc;
  emxArray_real_T *costab;
  emxArray_real_T *costab1q;
  emxArray_real_T *sintab;
  emxArray_real_T *sintabinv;
  const creal_T *x_data;
  creal_T *fv_data;
  creal_T *fy_data;
  creal_T *wwc_data;
  creal_T *y_data;
  double *costab1q_data;
  double *costab_data;
  double *sintab_data;
  double *sintabinv_data;
  int i;
  int k;
  int nd2;
  int nfft;
  x_data = x->data;
  if (x->size[0] == 1) {
    c_rtErrorWithMessageID(k_emlrtRTEI.fName, k_emlrtRTEI.lineNo);
  }
  nfft = x->size[0];
  if (x->size[0] == 0) {
    y->size[0] = 0;
  } else {
    double nt_re;
    int N2blue;
    int rt;
    boolean_T useRadix2;
    useRadix2 = ((x->size[0] & (x->size[0] - 1)) == 0);
    N2blue =
        FFTImplementationCallback_get_algo_sizes(x->size[0], useRadix2, &nd2);
    nt_re = 6.2831853071795862 / (double)nd2;
    rt = nd2 / 2 / 2;
    emxInit_real_T(&costab1q, 2);
    i = costab1q->size[0] * costab1q->size[1];
    costab1q->size[0] = 1;
    costab1q->size[1] = rt + 1;
    emxEnsureCapacity_real_T(costab1q, i);
    costab1q_data = costab1q->data;
    costab1q_data[0] = 1.0;
    nd2 = (int)((unsigned int)rt >> 1);
    if (nd2 > 2147483646) {
      check_forloop_overflow_error();
    }
    for (k = 0; k < nd2; k++) {
      costab1q_data[k + 1] = cos(nt_re * ((double)k + 1.0));
    }
    i = nd2 + 1;
    nd2 = rt - 1;
    for (k = i; k <= nd2; k++) {
      costab1q_data[k] = sin(nt_re * (double)(rt - k));
    }
    costab1q_data[rt] = 0.0;
    emxInit_real_T(&costab, 2);
    emxInit_real_T(&sintab, 2);
    emxInit_real_T(&sintabinv, 2);
    if (!useRadix2) {
      rt = costab1q->size[1] - 1;
      nd2 = (costab1q->size[1] - 1) << 1;
      i = costab->size[0] * costab->size[1];
      costab->size[0] = 1;
      costab->size[1] = nd2 + 1;
      emxEnsureCapacity_real_T(costab, i);
      costab_data = costab->data;
      i = sintab->size[0] * sintab->size[1];
      sintab->size[0] = 1;
      sintab->size[1] = nd2 + 1;
      emxEnsureCapacity_real_T(sintab, i);
      sintab_data = sintab->data;
      costab_data[0] = 1.0;
      sintab_data[0] = 0.0;
      i = sintabinv->size[0] * sintabinv->size[1];
      sintabinv->size[0] = 1;
      sintabinv->size[1] = nd2 + 1;
      emxEnsureCapacity_real_T(sintabinv, i);
      sintabinv_data = sintabinv->data;
      for (k = 0; k < rt; k++) {
        sintabinv_data[k + 1] = costab1q_data[(rt - k) - 1];
      }
      i = costab1q->size[1];
      for (k = i; k <= nd2; k++) {
        sintabinv_data[k] = costab1q_data[k - rt];
      }
      for (k = 0; k < rt; k++) {
        costab_data[k + 1] = costab1q_data[k + 1];
        sintab_data[k + 1] = -costab1q_data[(rt - k) - 1];
      }
      i = costab1q->size[1];
      for (k = i; k <= nd2; k++) {
        costab_data[k] = -costab1q_data[nd2 - k];
        sintab_data[k] = -costab1q_data[k - rt];
      }
    } else {
      rt = costab1q->size[1] - 1;
      nd2 = (costab1q->size[1] - 1) << 1;
      i = costab->size[0] * costab->size[1];
      costab->size[0] = 1;
      costab->size[1] = nd2 + 1;
      emxEnsureCapacity_real_T(costab, i);
      costab_data = costab->data;
      i = sintab->size[0] * sintab->size[1];
      sintab->size[0] = 1;
      sintab->size[1] = nd2 + 1;
      emxEnsureCapacity_real_T(sintab, i);
      sintab_data = sintab->data;
      costab_data[0] = 1.0;
      sintab_data[0] = 0.0;
      for (k = 0; k < rt; k++) {
        costab_data[k + 1] = costab1q_data[k + 1];
        sintab_data[k + 1] = -costab1q_data[(rt - k) - 1];
      }
      i = costab1q->size[1];
      for (k = i; k <= nd2; k++) {
        costab_data[k] = -costab1q_data[nd2 - k];
        sintab_data[k] = -costab1q_data[k - rt];
      }
      sintabinv->size[0] = 1;
      sintabinv->size[1] = 0;
    }
    emxFree_real_T(&costab1q);
    if (useRadix2) {
      FFTImplementationCallback_r2br_r2dit_trig_impl(x, x->size[0], costab,
                                                     sintab, y);
    } else {
      double b_re_tmp;
      double nt_im;
      double re_tmp;
      int nInt2;
      nd2 = (x->size[0] + x->size[0]) - 1;
      emxInit_creal_T(&wwc);
      if (nd2 < 0) {
        rtNonNegativeError(nd2, &emlrtDCI);
      }
      i = wwc->size[0];
      wwc->size[0] = nd2;
      emxEnsureCapacity_creal_T(wwc, i);
      wwc_data = wwc->data;
      rt = 0;
      wwc_data[x->size[0] - 1].re = 1.0;
      wwc_data[x->size[0] - 1].im = 0.0;
      nInt2 = x->size[0] << 1;
      i = x->size[0];
      for (k = 0; k <= i - 2; k++) {
        int b_y;
        b_y = ((k + 1) << 1) - 1;
        if (nInt2 - rt <= b_y) {
          rt += b_y - nInt2;
        } else {
          rt += b_y;
        }
        nt_im = -3.1415926535897931 * (double)rt / (double)nfft;
        wwc_data[(x->size[0] - k) - 2].re = cos(nt_im);
        wwc_data[(x->size[0] - k) - 2].im = -sin(nt_im);
      }
      i = nd2 - 1;
      for (k = i; k >= nfft; k--) {
        wwc_data[k] = wwc_data[(nd2 - k) - 1];
      }
      i = y->size[0];
      y->size[0] = x->size[0];
      emxEnsureCapacity_creal_T(y, i);
      y_data = y->data;
      nd2 = x->size[0];
      if (x->size[0] > 2147483646) {
        check_forloop_overflow_error();
      }
      for (k = 0; k < nd2; k++) {
        rt = (nfft + k) - 1;
        nt_re = wwc_data[rt].re;
        nt_im = wwc_data[rt].im;
        re_tmp = x_data[k].im;
        b_re_tmp = x_data[k].re;
        y_data[k].re = nt_re * b_re_tmp + nt_im * re_tmp;
        y_data[k].im = nt_re * re_tmp - nt_im * b_re_tmp;
      }
      rt = x->size[0] + 1;
      for (k = rt; k <= nfft; k++) {
        y_data[k - 1].re = 0.0;
        y_data[k - 1].im = 0.0;
      }
      emxInit_creal_T(&fy);
      FFTImplementationCallback_r2br_r2dit_trig_impl(y, N2blue, costab, sintab,
                                                     fy);
      fy_data = fy->data;
      emxInit_creal_T(&fv);
      FFTImplementationCallback_r2br_r2dit_trig_impl(wwc, N2blue, costab,
                                                     sintab, fv);
      fv_data = fv->data;
      nd2 = fy->size[0];
      for (i = 0; i < nd2; i++) {
        nt_re = fy_data[i].re;
        nt_im = fv_data[i].im;
        re_tmp = fy_data[i].im;
        b_re_tmp = fv_data[i].re;
        fy_data[i].re = nt_re * b_re_tmp - re_tmp * nt_im;
        fy_data[i].im = nt_re * nt_im + re_tmp * b_re_tmp;
      }
      FFTImplementationCallback_r2br_r2dit_trig_impl(fy, N2blue, costab,
                                                     sintabinv, fv);
      fv_data = fv->data;
      emxFree_creal_T(&fy);
      if (fv->size[0] > 1) {
        nt_re = 1.0 / (double)fv->size[0];
        nd2 = fv->size[0];
        for (i = 0; i < nd2; i++) {
          fv_data[i].re *= nt_re;
          fv_data[i].im *= nt_re;
        }
      }
      rt = x->size[0];
      nd2 = wwc->size[0];
      if ((x->size[0] <= wwc->size[0]) && (wwc->size[0] > 2147483646)) {
        check_forloop_overflow_error();
      }
      for (k = rt; k <= nd2; k++) {
        re_tmp = wwc_data[k - 1].re;
        b_re_tmp = fv_data[k - 1].im;
        nt_re = wwc_data[k - 1].im;
        nt_im = fv_data[k - 1].re;
        i = k - rt;
        y_data[i].re = re_tmp * nt_im + nt_re * b_re_tmp;
        y_data[i].im = re_tmp * b_re_tmp - nt_re * nt_im;
      }
      emxFree_creal_T(&fv);
      emxFree_creal_T(&wwc);
    }
    emxFree_real_T(&sintabinv);
    emxFree_real_T(&sintab);
    emxFree_real_T(&costab);
  }
}

void fft(const double x_data[], const int x_size[2], creal_T y_data[],
         int y_size[2])
{
  creal_T yCol_data[77];
  double costab_data[155];
  double sintab_data[155];
  double sintabinv_data[155];
  int nRows;
  if (x_size[1] == 0) {
    y_size[0] = 1;
    y_size[1] = 0;
  } else {
    int costab_size[2];
    int sintab_size[2];
    int sintabinv_size[2];
    int N2blue;
    boolean_T useRadix2;
    useRadix2 = ((x_size[1] & (x_size[1] - 1)) == 0);
    N2blue =
        FFTImplementationCallback_get_algo_sizes(x_size[1], useRadix2, &nRows);
    FFTImplementationCallback_generate_twiddle_tables(
        nRows, useRadix2, costab_data, costab_size, sintab_data, sintab_size,
        sintabinv_data, sintabinv_size);
    if (useRadix2) {
      FFTImplementationCallback_r2br_r2dit_trig(x_data, x_size[1], x_size[1],
                                                costab_data, costab_size,
                                                sintab_data, yCol_data);
    } else {
      FFTImplementationCallback_dobluesteinfft(
          x_data, x_size[1], N2blue, x_size[1], costab_data, costab_size,
          sintab_data, sintab_size, sintabinv_data, sintabinv_size, yCol_data);
    }
    y_size[0] = 1;
    y_size[1] = x_size[1];
    nRows = x_size[1];
    memcpy(&y_data[0], &yCol_data[0], (unsigned int)nRows * sizeof(creal_T));
  }
}

/* End of code generation (fft.c) */
