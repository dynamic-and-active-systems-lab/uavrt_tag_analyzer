/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * FFTImplementationCallback.c
 *
 * Code generation for function 'FFTImplementationCallback'
 *
 */

/* Include files */
#include "FFTImplementationCallback.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "uavrt_tag_analyzer_data.h"
#include "uavrt_tag_analyzer_emxutil.h"
#include "uavrt_tag_analyzer_internal_types.h"
#include "uavrt_tag_analyzer_rtwutil.h"
#include "uavrt_tag_analyzer_types.h"
#include <math.h>
#include <string.h>

/* Function Declarations */
static void c_FFTImplementationCallback_cal(int nfftLen, int wrapIndex_data[],
                                            int wrapIndex_size[2]);

static void c_FFTImplementationCallback_doH(const double x_data[], int x_size,
                                            creal_T y_data[], int *y_size,
                                            int unsigned_nRows,
                                            const double costab_data[],
                                            const int costab_size[2],
                                            const double sintab_data[]);

static void d_FFTImplementationCallback_doH(
    const double x_data[], int x_size, creal_T y_data[], int nrowsx, int nRows,
    int nfft, const creal_T wwc_data[], int wwc_size,
    const double costab_data[], const int costab_size[2],
    const double sintab_data[], const double costabinv_data[],
    const double sintabinv_data[]);

/* Function Definitions */
static void c_FFTImplementationCallback_cal(int nfftLen, int wrapIndex_data[],
                                            int wrapIndex_size[2])
{
  int b_i;
  int i;
  wrapIndex_size[0] = 1;
  wrapIndex_size[1] = nfftLen;
  if (nfftLen > 2147483646) {
    check_forloop_overflow_error();
  }
  i = (unsigned char)nfftLen;
  for (b_i = 0; b_i < i; b_i++) {
    if (b_i + 1 != 1) {
      wrapIndex_data[b_i] = (nfftLen - b_i) + 1;
    } else {
      wrapIndex_data[0] = 1;
    }
  }
}

static void c_FFTImplementationCallback_doH(const double x_data[], int x_size,
                                            creal_T y_data[], int *y_size,
                                            int unsigned_nRows,
                                            const double costab_data[],
                                            const int costab_size[2],
                                            const double sintab_data[])
{
  emxArray_creal_T *y;
  creal_T reconVar1_data[38];
  creal_T reconVar2_data[38];
  creal_T *b_y_data;
  double hcostab_data[77];
  double hsintab_data[77];
  double b_y_re_tmp;
  double c_y_re_tmp;
  double d_y_re_tmp;
  double temp2_im;
  double temp2_re;
  double temp_im;
  double temp_im_tmp;
  double temp_re;
  double temp_re_tmp;
  double y_re_tmp;
  double z_tmp;
  int bitrevIndex_data[39];
  int wrapIndex_data[38];
  int hszCostab;
  int i;
  int iDelta;
  int iheight;
  int iy;
  int ju;
  int k;
  int nRows;
  int nRowsD2;
  int u0;
  boolean_T tst;
  nRows = unsigned_nRows / 2;
  u0 = *y_size;
  if (u0 > nRows) {
    u0 = nRows;
  }
  iheight = nRows - 2;
  nRowsD2 = nRows / 2;
  k = nRowsD2 / 2;
  hszCostab = (int)((unsigned int)costab_size[1] >> 1);
  for (i = 0; i < hszCostab; i++) {
    iy = ((i + 1) << 1) - 2;
    hcostab_data[i] = costab_data[iy];
    hsintab_data[i] = sintab_data[iy];
  }
  ju = (unsigned char)nRows;
  for (i = 0; i < ju; i++) {
    temp_re = sintab_data[i];
    temp_im = costab_data[i];
    reconVar1_data[i].re = temp_re + 1.0;
    reconVar1_data[i].im = -temp_im;
    reconVar2_data[i].re = 1.0 - temp_re;
    reconVar2_data[i].im = temp_im;
  }
  int wrapIndex_size[2];
  c_FFTImplementationCallback_cal(nRows, wrapIndex_data, wrapIndex_size);
  z_tmp = (double)unsigned_nRows / 2.0;
  ju = 0;
  iy = 1;
  hszCostab = (int)((double)unsigned_nRows / 2.0);
  if (hszCostab - 1 >= 0) {
    memset(&bitrevIndex_data[0], 0, (unsigned int)hszCostab * sizeof(int));
  }
  for (iDelta = 0; iDelta <= u0 - 2; iDelta++) {
    bitrevIndex_data[iDelta] = iy;
    hszCostab = (int)z_tmp;
    tst = true;
    while (tst) {
      hszCostab >>= 1;
      ju ^= hszCostab;
      tst = ((ju & hszCostab) == 0);
    }
    iy = ju + 1;
  }
  bitrevIndex_data[u0 - 1] = iy;
  if ((x_size & 1) == 0) {
    tst = true;
    u0 = x_size;
  } else if (x_size >= unsigned_nRows) {
    tst = true;
    u0 = unsigned_nRows;
  } else {
    tst = false;
    u0 = x_size - 1;
  }
  if (u0 <= unsigned_nRows) {
    hszCostab = u0;
  } else {
    hszCostab = unsigned_nRows;
  }
  temp_re = (double)hszCostab / 2.0;
  if (u0 > unsigned_nRows) {
    u0 = unsigned_nRows;
  }
  ju = (int)((double)u0 / 2.0);
  for (i = 0; i < ju; i++) {
    iy = i << 1;
    hszCostab = bitrevIndex_data[i];
    y_data[hszCostab - 1].re = x_data[iy];
    y_data[hszCostab - 1].im = x_data[iy + 1];
  }
  if (!tst) {
    ju = bitrevIndex_data[(int)temp_re] - 1;
    y_data[ju].re = x_data[(int)temp_re << 1];
    y_data[ju].im = 0.0;
  }
  emxInit_creal_T(&y);
  ju = y->size[0];
  y->size[0] = *y_size;
  emxEnsureCapacity_creal_T(y, ju);
  b_y_data = y->data;
  for (ju = 0; ju < *y_size; ju++) {
    b_y_data[ju] = y_data[ju];
  }
  if (nRows > 1) {
    for (i = 0; i <= iheight; i += 2) {
      temp_re_tmp = b_y_data[i + 1].re;
      temp_im_tmp = b_y_data[i + 1].im;
      temp_re = b_y_data[i].re;
      temp_im = b_y_data[i].im;
      b_y_data[i + 1].re = temp_re - temp_re_tmp;
      b_y_data[i + 1].im = temp_im - temp_im_tmp;
      b_y_data[i].re = temp_re + temp_re_tmp;
      b_y_data[i].im = temp_im + temp_im_tmp;
    }
  }
  iDelta = 2;
  nRows = 4;
  iheight = ((k - 1) << 2) + 1;
  while (k > 0) {
    for (i = 0; i < iheight; i += nRows) {
      hszCostab = i + iDelta;
      temp_re = b_y_data[hszCostab].re;
      temp_im = b_y_data[hszCostab].im;
      b_y_data[hszCostab].re = b_y_data[i].re - temp_re;
      b_y_data[hszCostab].im = b_y_data[i].im - temp_im;
      b_y_data[i].re += temp_re;
      b_y_data[i].im += temp_im;
    }
    hszCostab = 1;
    for (iy = k; iy < nRowsD2; iy += k) {
      temp2_re = hcostab_data[iy];
      temp2_im = hsintab_data[iy];
      i = hszCostab;
      ju = hszCostab + iheight;
      while (i < ju) {
        u0 = i + iDelta;
        temp_re_tmp = b_y_data[u0].im;
        y_re_tmp = b_y_data[u0].re;
        temp_re = temp2_re * y_re_tmp - temp2_im * temp_re_tmp;
        temp_im = temp2_re * temp_re_tmp + temp2_im * y_re_tmp;
        b_y_data[u0].re = b_y_data[i].re - temp_re;
        b_y_data[u0].im = b_y_data[i].im - temp_im;
        b_y_data[i].re += temp_re;
        b_y_data[i].im += temp_im;
        i += nRows;
      }
      hszCostab++;
    }
    k /= 2;
    iDelta = nRows;
    nRows += nRows;
    iheight -= iDelta;
  }
  *y_size = y->size[0];
  hszCostab = y->size[0];
  for (ju = 0; ju < hszCostab; ju++) {
    y_data[ju] = b_y_data[ju];
  }
  hszCostab = (int)z_tmp / 2;
  y_re_tmp = b_y_data[0].re * reconVar1_data[0].re;
  temp_re = b_y_data[0].re * reconVar1_data[0].im;
  b_y_re_tmp = b_y_data[0].re * reconVar2_data[0].re;
  temp_im = b_y_data[0].re * reconVar2_data[0].im;
  y_data[0].re = 0.5 * ((y_re_tmp - b_y_data[0].im * reconVar1_data[0].im) +
                        (b_y_re_tmp - -b_y_data[0].im * reconVar2_data[0].im));
  y_data[0].im = 0.5 * ((temp_re + b_y_data[0].im * reconVar1_data[0].re) +
                        (temp_im + -b_y_data[0].im * reconVar2_data[0].re));
  y_data[(int)z_tmp].re =
      0.5 * ((b_y_re_tmp - b_y_data[0].im * reconVar2_data[0].im) +
             (y_re_tmp - -b_y_data[0].im * reconVar1_data[0].im));
  y_data[(int)z_tmp].im =
      0.5 * ((temp_im + b_y_data[0].im * reconVar2_data[0].re) +
             (temp_re + -b_y_data[0].im * reconVar1_data[0].re));
  emxFree_creal_T(&y);
  for (i = 2; i <= hszCostab; i++) {
    double temp2_im_tmp;
    temp_re_tmp = y_data[i - 1].re;
    temp_im_tmp = y_data[i - 1].im;
    ju = wrapIndex_data[i - 1];
    temp2_im = y_data[ju - 1].re;
    temp2_im_tmp = y_data[ju - 1].im;
    y_re_tmp = reconVar1_data[i - 1].im;
    b_y_re_tmp = reconVar1_data[i - 1].re;
    c_y_re_tmp = reconVar2_data[i - 1].im;
    d_y_re_tmp = reconVar2_data[i - 1].re;
    y_data[i - 1].re =
        0.5 * ((temp_re_tmp * b_y_re_tmp - temp_im_tmp * y_re_tmp) +
               (temp2_im * d_y_re_tmp - -temp2_im_tmp * c_y_re_tmp));
    y_data[i - 1].im =
        0.5 * ((temp_re_tmp * y_re_tmp + temp_im_tmp * b_y_re_tmp) +
               (temp2_im * c_y_re_tmp + -temp2_im_tmp * d_y_re_tmp));
    iy = ((int)z_tmp + i) - 1;
    y_data[iy].re =
        0.5 * ((temp_re_tmp * d_y_re_tmp - temp_im_tmp * c_y_re_tmp) +
               (temp2_im * b_y_re_tmp - -temp2_im_tmp * y_re_tmp));
    y_data[iy].im =
        0.5 * ((temp_re_tmp * c_y_re_tmp + temp_im_tmp * d_y_re_tmp) +
               (temp2_im * y_re_tmp + -temp2_im_tmp * b_y_re_tmp));
    temp_im = reconVar1_data[ju - 1].im;
    temp_re = reconVar1_data[ju - 1].re;
    y_re_tmp = reconVar2_data[ju - 1].im;
    temp2_re = reconVar2_data[ju - 1].re;
    y_data[ju - 1].re =
        0.5 * ((temp2_im * temp_re - temp2_im_tmp * temp_im) +
               (temp_re_tmp * temp2_re - -temp_im_tmp * y_re_tmp));
    y_data[ju - 1].im =
        0.5 * ((temp2_im * temp_im + temp2_im_tmp * temp_re) +
               (temp_re_tmp * y_re_tmp + -temp_im_tmp * temp2_re));
    ju = (ju + (int)z_tmp) - 1;
    y_data[ju].re = 0.5 * ((temp2_im * temp2_re - temp2_im_tmp * y_re_tmp) +
                           (temp_re_tmp * temp_re - -temp_im_tmp * temp_im));
    y_data[ju].im = 0.5 * ((temp2_im * y_re_tmp + temp2_im_tmp * temp2_re) +
                           (temp_re_tmp * temp_im + -temp_im_tmp * temp_re));
  }
  if (hszCostab != 0) {
    temp_re_tmp = y_data[hszCostab].re;
    temp_im_tmp = y_data[hszCostab].im;
    y_re_tmp = reconVar1_data[hszCostab].im;
    b_y_re_tmp = reconVar1_data[hszCostab].re;
    c_y_re_tmp = temp_re_tmp * b_y_re_tmp;
    temp_re = temp_re_tmp * y_re_tmp;
    d_y_re_tmp = reconVar2_data[hszCostab].im;
    temp2_re = reconVar2_data[hszCostab].re;
    temp2_im = temp_re_tmp * temp2_re;
    temp_im = temp_re_tmp * d_y_re_tmp;
    y_data[hszCostab].re = 0.5 * ((c_y_re_tmp - temp_im_tmp * y_re_tmp) +
                                  (temp2_im - -temp_im_tmp * d_y_re_tmp));
    y_data[hszCostab].im = 0.5 * ((temp_re + temp_im_tmp * b_y_re_tmp) +
                                  (temp_im + -temp_im_tmp * temp2_re));
    ju = (int)z_tmp + hszCostab;
    y_data[ju].re = 0.5 * ((temp2_im - temp_im_tmp * d_y_re_tmp) +
                           (c_y_re_tmp - -temp_im_tmp * y_re_tmp));
    y_data[ju].im = 0.5 * ((temp_im + temp_im_tmp * temp2_re) +
                           (temp_re + -temp_im_tmp * b_y_re_tmp));
  }
}

static void d_FFTImplementationCallback_doH(
    const double x_data[], int x_size, creal_T y_data[], int nrowsx, int nRows,
    int nfft, const creal_T wwc_data[], int wwc_size,
    const double costab_data[], const int costab_size[2],
    const double sintab_data[], const double costabinv_data[],
    const double sintabinv_data[])
{
  emxArray_creal_T b_fy_data;
  emxArray_creal_T b_wwc_data;
  emxArray_creal_T *b_y;
  emxArray_creal_T *y;
  emxArray_real_T b_hcostab_data;
  emxArray_real_T b_hcostabinv_data;
  emxArray_real_T b_hsintab_data;
  emxArray_real_T b_hsintabinv_data;
  emxArray_real_T *costab;
  emxArray_real_T *costab1q;
  emxArray_real_T *sintab;
  creal_T fy_data[154];
  creal_T reconVar1_data[38];
  creal_T reconVar2_data[38];
  creal_T ytmp_data[38];
  creal_T *c_y_data;
  creal_T *d_y_data;
  cuint8_T b_y_data[77];
  double hcostab_data[77];
  double hcostabinv_data[77];
  double hsintab_data[77];
  double hsintabinv_data[77];
  double e;
  double temp_im;
  double temp_re;
  double temp_re_tmp;
  double twid_im;
  double twid_re;
  double z;
  double *b_costab_data;
  double *b_sintab_data;
  double *costab1q_data;
  int wrapIndex_data[38];
  int hcostab_size[2];
  int hcostabinv_size[2];
  int hsintab_size[2];
  int hsintabinv_size[2];
  int b_i;
  int fy_size;
  int hnRows;
  int i;
  int iDelta;
  int iDelta2;
  int iheight;
  int j;
  int ju;
  int k;
  int k1;
  int nRowsD2;
  int nd2;
  boolean_T tst;
  hnRows = nRows / 2;
  if (hnRows > nrowsx) {
    if (hnRows - 1 >= 0) {
      memset(&b_y_data[0], 0, (unsigned int)hnRows * sizeof(cuint8_T));
    }
  }
  for (i = 0; i < hnRows; i++) {
    ytmp_data[i].re = 0.0;
    ytmp_data[i].im = b_y_data[i].im;
  }
  if ((x_size & 1) == 0) {
    tst = true;
    ju = x_size;
  } else if (x_size >= nRows) {
    tst = true;
    ju = nRows;
  } else {
    tst = false;
    ju = x_size - 1;
  }
  if (ju > nRows) {
    ju = nRows;
  }
  nd2 = nRows << 1;
  e = 6.2831853071795862 / (double)nd2;
  iDelta = nd2 / 2 / 2;
  emxInit_real_T(&costab1q, 2);
  i = costab1q->size[0] * costab1q->size[1];
  costab1q->size[0] = 1;
  costab1q->size[1] = iDelta + 1;
  emxEnsureCapacity_real_T(costab1q, i);
  costab1q_data = costab1q->data;
  costab1q_data[0] = 1.0;
  nd2 = (int)((unsigned int)iDelta >> 1);
  if (nd2 > 2147483646) {
    check_forloop_overflow_error();
  }
  for (k = 0; k < nd2; k++) {
    costab1q_data[k + 1] = cos(e * ((double)k + 1.0));
  }
  i = nd2 + 1;
  j = iDelta - 1;
  for (k = i; k <= j; k++) {
    costab1q_data[k] = sin(e * (double)(iDelta - k));
  }
  costab1q_data[iDelta] = 0.0;
  iDelta = costab1q->size[1] - 1;
  nd2 = (costab1q->size[1] - 1) << 1;
  emxInit_real_T(&costab, 2);
  i = costab->size[0] * costab->size[1];
  costab->size[0] = 1;
  costab->size[1] = nd2 + 1;
  emxEnsureCapacity_real_T(costab, i);
  b_costab_data = costab->data;
  emxInit_real_T(&sintab, 2);
  i = sintab->size[0] * sintab->size[1];
  sintab->size[0] = 1;
  sintab->size[1] = nd2 + 1;
  emxEnsureCapacity_real_T(sintab, i);
  b_sintab_data = sintab->data;
  b_costab_data[0] = 1.0;
  b_sintab_data[0] = 0.0;
  for (k = 0; k < iDelta; k++) {
    b_costab_data[k + 1] = costab1q_data[k + 1];
    b_sintab_data[k + 1] = -costab1q_data[(iDelta - k) - 1];
  }
  i = costab1q->size[1];
  for (k = i; k <= nd2; k++) {
    b_costab_data[k] = -costab1q_data[nd2 - k];
    b_sintab_data[k] = -costab1q_data[k - iDelta];
  }
  emxFree_real_T(&costab1q);
  nd2 = (int)((unsigned int)costab_size[1] >> 1);
  hcostab_size[0] = 1;
  hcostab_size[1] = nd2;
  hsintab_size[0] = 1;
  hsintab_size[1] = nd2;
  hcostabinv_size[0] = 1;
  hcostabinv_size[1] = nd2;
  hsintabinv_size[0] = 1;
  hsintabinv_size[1] = nd2;
  for (b_i = 0; b_i < nd2; b_i++) {
    j = ((b_i + 1) << 1) - 2;
    hcostab_data[b_i] = costab_data[j];
    hsintab_data[b_i] = sintab_data[j];
    hcostabinv_data[b_i] = costabinv_data[j];
    hsintabinv_data[b_i] = sintabinv_data[j];
  }
  i = (unsigned char)hnRows;
  for (b_i = 0; b_i < i; b_i++) {
    j = b_i << 1;
    e = b_sintab_data[j];
    temp_im = b_costab_data[j];
    reconVar1_data[b_i].re = e + 1.0;
    reconVar1_data[b_i].im = -temp_im;
    reconVar2_data[b_i].re = 1.0 - e;
    reconVar2_data[b_i].im = temp_im;
  }
  int wrapIndex_size[2];
  emxFree_real_T(&sintab);
  emxFree_real_T(&costab);
  c_FFTImplementationCallback_cal(hnRows, wrapIndex_data, wrapIndex_size);
  e = (double)ju / 2.0;
  j = (int)e;
  for (k1 = 0; k1 < j; k1++) {
    nd2 = (hnRows + k1) - 1;
    temp_re = wwc_data[nd2].re;
    temp_im = wwc_data[nd2].im;
    nd2 = k1 << 1;
    twid_re = x_data[nd2];
    twid_im = x_data[nd2 + 1];
    ytmp_data[k1].re = temp_re * twid_re + temp_im * twid_im;
    ytmp_data[k1].im = temp_re * twid_im - temp_im * twid_re;
  }
  if (!tst) {
    nd2 = (hnRows + (int)e) - 1;
    temp_re = wwc_data[nd2].re;
    temp_im = wwc_data[nd2].im;
    twid_re = x_data[(int)e << 1];
    ytmp_data[(int)((double)ju / 2.0)].re = temp_re * twid_re + temp_im * 0.0;
    ytmp_data[(int)((double)ju / 2.0)].im = temp_re * 0.0 - temp_im * twid_re;
    if ((int)e + 2 <= hnRows) {
      j = (int)e + 2;
      if (j <= hnRows) {
        memset(&ytmp_data[j + -1], 0,
               (unsigned int)((hnRows - j) + 1) * sizeof(creal_T));
      }
    }
  } else if ((int)e + 1 <= hnRows) {
    j = (int)e + 1;
    if (j <= hnRows) {
      memset(&ytmp_data[j + -1], 0,
             (unsigned int)((hnRows - j) + 1) * sizeof(creal_T));
    }
  }
  z = (double)nfft / 2.0;
  emxInit_creal_T(&y);
  nd2 = (int)z;
  j = y->size[0];
  y->size[0] = (int)z;
  emxEnsureCapacity_creal_T(y, j);
  c_y_data = y->data;
  if ((int)z > hnRows) {
    j = y->size[0];
    y->size[0] = (int)z;
    emxEnsureCapacity_creal_T(y, j);
    c_y_data = y->data;
    for (j = 0; j < nd2; j++) {
      c_y_data[j].re = 0.0;
      c_y_data[j].im = 0.0;
    }
  }
  fy_size = y->size[0];
  nd2 = y->size[0];
  for (j = 0; j < nd2; j++) {
    fy_data[j] = c_y_data[j];
  }
  j = (int)z;
  if (hnRows <= j) {
    j = hnRows;
  }
  k1 = (int)z - 2;
  nRowsD2 = (int)z / 2;
  k = nRowsD2 / 2;
  nd2 = 0;
  ju = 0;
  for (b_i = 0; b_i <= j - 2; b_i++) {
    fy_data[nd2] = ytmp_data[b_i];
    iDelta = (int)z;
    tst = true;
    while (tst) {
      iDelta >>= 1;
      ju ^= iDelta;
      tst = ((ju & iDelta) == 0);
    }
    nd2 = ju;
  }
  fy_data[nd2] = ytmp_data[j - 1];
  j = y->size[0];
  y->size[0] = fy_size;
  emxEnsureCapacity_creal_T(y, j);
  c_y_data = y->data;
  nd2 = fy_size;
  for (j = 0; j < nd2; j++) {
    c_y_data[j] = fy_data[j];
  }
  if ((int)z > 1) {
    for (b_i = 0; b_i <= k1; b_i += 2) {
      temp_re_tmp = c_y_data[b_i + 1].re;
      e = c_y_data[b_i + 1].im;
      temp_im = c_y_data[b_i].re;
      temp_re = c_y_data[b_i].im;
      c_y_data[b_i + 1].re = temp_im - temp_re_tmp;
      c_y_data[b_i + 1].im = temp_re - e;
      c_y_data[b_i].re = temp_im + temp_re_tmp;
      c_y_data[b_i].im = temp_re + e;
    }
  }
  iDelta = 2;
  iDelta2 = 4;
  iheight = ((k - 1) << 2) + 1;
  while (k > 0) {
    for (b_i = 0; b_i < iheight; b_i += iDelta2) {
      nd2 = b_i + iDelta;
      temp_re = c_y_data[nd2].re;
      temp_im = c_y_data[nd2].im;
      c_y_data[nd2].re = c_y_data[b_i].re - temp_re;
      c_y_data[nd2].im = c_y_data[b_i].im - temp_im;
      c_y_data[b_i].re += temp_re;
      c_y_data[b_i].im += temp_im;
    }
    nd2 = 1;
    for (j = k; j < nRowsD2; j += k) {
      twid_re = hcostab_data[j];
      twid_im = hsintab_data[j];
      b_i = nd2;
      ju = nd2 + iheight;
      while (b_i < ju) {
        k1 = b_i + iDelta;
        temp_re_tmp = c_y_data[k1].im;
        e = c_y_data[k1].re;
        temp_re = twid_re * e - twid_im * temp_re_tmp;
        temp_im = twid_re * temp_re_tmp + twid_im * e;
        c_y_data[k1].re = c_y_data[b_i].re - temp_re;
        c_y_data[k1].im = c_y_data[b_i].im - temp_im;
        c_y_data[b_i].re += temp_re;
        c_y_data[b_i].im += temp_im;
        b_i += iDelta2;
      }
      nd2++;
    }
    k /= 2;
    iDelta = iDelta2;
    iDelta2 += iDelta2;
    iheight -= iDelta;
  }
  b_wwc_data.data = (creal_T *)&wwc_data[0];
  b_wwc_data.size = &wwc_size;
  b_wwc_data.allocatedSize = -1;
  b_wwc_data.numDimensions = 1;
  b_wwc_data.canFreeData = false;
  b_hcostab_data.data = &hcostab_data[0];
  b_hcostab_data.size = &hcostab_size[0];
  b_hcostab_data.allocatedSize = 77;
  b_hcostab_data.numDimensions = 2;
  b_hcostab_data.canFreeData = false;
  b_hsintab_data.data = &hsintab_data[0];
  b_hsintab_data.size = &hsintab_size[0];
  b_hsintab_data.allocatedSize = 77;
  b_hsintab_data.numDimensions = 2;
  b_hsintab_data.canFreeData = false;
  emxInit_creal_T(&b_y);
  d_FFTImplementationCallback_r2b(&b_wwc_data, (int)z, &b_hcostab_data,
                                  &b_hsintab_data, b_y);
  d_y_data = b_y->data;
  fy_size = y->size[0];
  nd2 = y->size[0];
  for (j = 0; j < nd2; j++) {
    e = c_y_data[j].re;
    temp_im = d_y_data[j].im;
    temp_re = c_y_data[j].im;
    twid_re = d_y_data[j].re;
    fy_data[j].re = e * twid_re - temp_re * temp_im;
    fy_data[j].im = e * temp_im + temp_re * twid_re;
  }
  emxFree_creal_T(&b_y);
  b_fy_data.data = &fy_data[0];
  b_fy_data.size = &fy_size;
  b_fy_data.allocatedSize = 154;
  b_fy_data.numDimensions = 1;
  b_fy_data.canFreeData = false;
  b_hcostabinv_data.data = &hcostabinv_data[0];
  b_hcostabinv_data.size = &hcostabinv_size[0];
  b_hcostabinv_data.allocatedSize = 77;
  b_hcostabinv_data.numDimensions = 2;
  b_hcostabinv_data.canFreeData = false;
  b_hsintabinv_data.data = &hsintabinv_data[0];
  b_hsintabinv_data.size = &hsintabinv_size[0];
  b_hsintabinv_data.allocatedSize = 77;
  b_hsintabinv_data.numDimensions = 2;
  b_hsintabinv_data.canFreeData = false;
  d_FFTImplementationCallback_r2b(&b_fy_data, (int)z, &b_hcostabinv_data,
                                  &b_hsintabinv_data, y);
  c_y_data = y->data;
  if (y->size[0] > 1) {
    e = 1.0 / (double)y->size[0];
    nd2 = y->size[0];
    for (j = 0; j < nd2; j++) {
      c_y_data[j].re *= e;
      c_y_data[j].im *= e;
    }
  }
  j = wwc_size;
  for (k = hnRows; k <= j; k++) {
    e = wwc_data[k - 1].re;
    temp_im = c_y_data[k - 1].im;
    temp_re = wwc_data[k - 1].im;
    twid_re = c_y_data[k - 1].re;
    nd2 = k - hnRows;
    ytmp_data[nd2].re = e * twid_re + temp_re * temp_im;
    ytmp_data[nd2].im = e * temp_im - temp_re * twid_re;
  }
  emxFree_creal_T(&y);
  for (b_i = 0; b_i < i; b_i++) {
    double ytmp_re_tmp;
    j = wrapIndex_data[b_i];
    e = ytmp_data[b_i].re;
    temp_im = reconVar1_data[b_i].im;
    temp_re = ytmp_data[b_i].im;
    twid_re = reconVar1_data[b_i].re;
    twid_im = ytmp_data[j - 1].re;
    temp_re_tmp = -ytmp_data[j - 1].im;
    z = reconVar2_data[b_i].im;
    ytmp_re_tmp = reconVar2_data[b_i].re;
    y_data[b_i].re = 0.5 * ((e * twid_re - temp_re * temp_im) +
                            (twid_im * ytmp_re_tmp - temp_re_tmp * z));
    y_data[b_i].im = 0.5 * ((e * temp_im + temp_re * twid_re) +
                            (twid_im * z + temp_re_tmp * ytmp_re_tmp));
    j = hnRows + b_i;
    y_data[j].re = 0.5 * ((e * ytmp_re_tmp - temp_re * z) +
                          (twid_im * twid_re - temp_re_tmp * temp_im));
    y_data[j].im = 0.5 * ((e * z + temp_re * ytmp_re_tmp) +
                          (twid_im * temp_im + temp_re_tmp * twid_re));
  }
}

int c_FFTImplementationCallback_dob(
    const double x_data[], int x_size, int n2blue, int nfft,
    const double costab_data[], const int costab_size[2],
    const double sintab_data[], const int sintab_size[2],
    const double sintabinv_data[], const int sintabinv_size[2],
    creal_T y_data[])
{
  emxArray_creal_T b_fy_data;
  emxArray_creal_T b_wwc_data;
  emxArray_creal_T b_y_data;
  emxArray_creal_T *b_y;
  emxArray_real_T b_costab_data;
  emxArray_real_T b_sintab_data;
  emxArray_real_T b_sintabinv_data;
  emxArray_real_T c_costab_data;
  emxArray_real_T c_sintab_data;
  emxArray_real_T d_costab_data;
  creal_T fy_data[308];
  creal_T wwc_data[153];
  creal_T *c_y_data;
  double nt_im;
  int fy_size;
  int i;
  int k;
  int minNrowsNx;
  int wwc_size;
  int y;
  int y_size;
  if ((nfft != 1) && ((nfft & 1) == 0)) {
    int nInt2;
    int nInt2m1;
    int nRows;
    int rt;
    nRows = nfft / 2;
    nInt2m1 = (nRows + nRows) - 1;
    if (nInt2m1 < 0) {
      rtNonNegativeError(nInt2m1, &emlrtDCI);
    }
    wwc_size = nInt2m1;
    rt = 0;
    wwc_data[nRows - 1].re = 1.0;
    wwc_data[nRows - 1].im = 0.0;
    nInt2 = nRows << 1;
    i = (unsigned char)(nRows - 1);
    for (k = 0; k < i; k++) {
      y = ((k + 1) << 1) - 1;
      if (nInt2 - rt <= y) {
        rt += y - nInt2;
      } else {
        rt += y;
      }
      nt_im = -3.1415926535897931 * (double)rt / (double)nRows;
      minNrowsNx = (nRows - k) - 2;
      wwc_data[minNrowsNx].re = cos(nt_im);
      wwc_data[minNrowsNx].im = -sin(nt_im);
    }
    i = nInt2m1 - 1;
    for (k = i; k >= nRows; k--) {
      wwc_data[k] = wwc_data[(nInt2m1 - k) - 1];
    }
  } else {
    int nInt2;
    int nInt2m1;
    int rt;
    nInt2m1 = (nfft + nfft) - 1;
    if (nInt2m1 < 0) {
      rtNonNegativeError(nInt2m1, &emlrtDCI);
    }
    wwc_size = nInt2m1;
    rt = 0;
    wwc_data[nfft - 1].re = 1.0;
    wwc_data[nfft - 1].im = 0.0;
    nInt2 = nfft << 1;
    if (nfft - 1 > 2147483646) {
      check_forloop_overflow_error();
    }
    i = (unsigned char)(nfft - 1);
    for (k = 0; k < i; k++) {
      y = ((k + 1) << 1) - 1;
      if (nInt2 - rt <= y) {
        rt += y - nInt2;
      } else {
        rt += y;
      }
      nt_im = -3.1415926535897931 * (double)rt / (double)nfft;
      minNrowsNx = (nfft - k) - 2;
      wwc_data[minNrowsNx].re = cos(nt_im);
      wwc_data[minNrowsNx].im = -sin(nt_im);
    }
    i = nInt2m1 - 1;
    for (k = i; k >= nfft; k--) {
      wwc_data[k] = wwc_data[(nInt2m1 - k) - 1];
    }
  }
  y_size = nfft;
  if (nfft > x_size) {
    y_size = nfft;
    memset(&y_data[0], 0, (unsigned int)nfft * sizeof(creal_T));
  }
  emxInit_creal_T(&b_y);
  if ((n2blue != 1) && ((nfft & 1) == 0)) {
    d_FFTImplementationCallback_doH(
        x_data, x_size, y_data, x_size, nfft, n2blue, wwc_data, wwc_size,
        costab_data, costab_size, sintab_data, costab_data, sintabinv_data);
  } else {
    double b_re_tmp;
    double c_re_tmp;
    double re_tmp;
    if (nfft <= x_size) {
      minNrowsNx = nfft;
    } else {
      minNrowsNx = x_size;
    }
    i = (unsigned char)minNrowsNx;
    for (k = 0; k < i; k++) {
      y = (nfft + k) - 1;
      nt_im = x_data[k];
      y_data[k].re = wwc_data[y].re * nt_im;
      y_data[k].im = wwc_data[y].im * -nt_im;
    }
    y = minNrowsNx + 1;
    if ((minNrowsNx + 1 <= nfft) && (nfft > 2147483646)) {
      check_forloop_overflow_error();
    }
    if (y <= nfft) {
      memset(&y_data[y + -1], 0,
             (unsigned int)((nfft - y) + 1) * sizeof(creal_T));
    }
    b_y_data.data = &y_data[0];
    b_y_data.size = &y_size;
    b_y_data.allocatedSize = -1;
    b_y_data.numDimensions = 1;
    b_y_data.canFreeData = false;
    b_costab_data.data = (double *)&costab_data[0];
    b_costab_data.size = (int *)&costab_size[0];
    b_costab_data.allocatedSize = -1;
    b_costab_data.numDimensions = 2;
    b_costab_data.canFreeData = false;
    b_sintab_data.data = (double *)&sintab_data[0];
    b_sintab_data.size = (int *)&sintab_size[0];
    b_sintab_data.allocatedSize = -1;
    b_sintab_data.numDimensions = 2;
    b_sintab_data.canFreeData = false;
    d_FFTImplementationCallback_r2b(&b_y_data, n2blue, &b_costab_data,
                                    &b_sintab_data, b_y);
    c_y_data = b_y->data;
    fy_size = b_y->size[0];
    y = b_y->size[0];
    for (i = 0; i < y; i++) {
      fy_data[i] = c_y_data[i];
    }
    b_wwc_data.data = &wwc_data[0];
    b_wwc_data.size = &wwc_size;
    b_wwc_data.allocatedSize = 153;
    b_wwc_data.numDimensions = 1;
    b_wwc_data.canFreeData = false;
    c_costab_data.data = (double *)&costab_data[0];
    c_costab_data.size = (int *)&costab_size[0];
    c_costab_data.allocatedSize = -1;
    c_costab_data.numDimensions = 2;
    c_costab_data.canFreeData = false;
    c_sintab_data.data = (double *)&sintab_data[0];
    c_sintab_data.size = (int *)&sintab_size[0];
    c_sintab_data.allocatedSize = -1;
    c_sintab_data.numDimensions = 2;
    c_sintab_data.canFreeData = false;
    d_FFTImplementationCallback_r2b(&b_wwc_data, n2blue, &c_costab_data,
                                    &c_sintab_data, b_y);
    c_y_data = b_y->data;
    y = fy_size;
    for (i = 0; i < y; i++) {
      nt_im = fy_data[i].re;
      re_tmp = c_y_data[i].im;
      b_re_tmp = fy_data[i].im;
      c_re_tmp = c_y_data[i].re;
      fy_data[i].re = nt_im * c_re_tmp - b_re_tmp * re_tmp;
      fy_data[i].im = nt_im * re_tmp + b_re_tmp * c_re_tmp;
    }
    b_fy_data.data = &fy_data[0];
    b_fy_data.size = &fy_size;
    b_fy_data.allocatedSize = 308;
    b_fy_data.numDimensions = 1;
    b_fy_data.canFreeData = false;
    d_costab_data.data = (double *)&costab_data[0];
    d_costab_data.size = (int *)&costab_size[0];
    d_costab_data.allocatedSize = -1;
    d_costab_data.numDimensions = 2;
    d_costab_data.canFreeData = false;
    b_sintabinv_data.data = (double *)&sintabinv_data[0];
    b_sintabinv_data.size = (int *)&sintabinv_size[0];
    b_sintabinv_data.allocatedSize = -1;
    b_sintabinv_data.numDimensions = 2;
    b_sintabinv_data.canFreeData = false;
    d_FFTImplementationCallback_r2b(&b_fy_data, n2blue, &d_costab_data,
                                    &b_sintabinv_data, b_y);
    c_y_data = b_y->data;
    if (b_y->size[0] > 1) {
      nt_im = 1.0 / (double)b_y->size[0];
      y = b_y->size[0];
      for (i = 0; i < y; i++) {
        c_y_data[i].re *= nt_im;
        c_y_data[i].im *= nt_im;
      }
    }
    i = wwc_size;
    for (k = nfft; k <= i; k++) {
      nt_im = wwc_data[k - 1].re;
      re_tmp = c_y_data[k - 1].im;
      b_re_tmp = wwc_data[k - 1].im;
      c_re_tmp = c_y_data[k - 1].re;
      minNrowsNx = k - nfft;
      y_data[minNrowsNx].re = nt_im * c_re_tmp + b_re_tmp * re_tmp;
      y_data[minNrowsNx].im = nt_im * re_tmp - b_re_tmp * c_re_tmp;
    }
  }
  emxFree_creal_T(&b_y);
  return y_size;
}

void c_FFTImplementationCallback_gen(int nRows, boolean_T useRadix2,
                                     double costab_data[], int costab_size[2],
                                     double sintab_data[], int sintab_size[2],
                                     double sintabinv_data[],
                                     int sintabinv_size[2])
{
  emxArray_real_T *costab;
  emxArray_real_T *costab1q;
  emxArray_real_T *sintab;
  emxArray_real_T *sintabinv;
  double e;
  double *b_costab_data;
  double *b_sintab_data;
  double *b_sintabinv_data;
  double *costab1q_data;
  int i;
  int k;
  int n;
  int nd2;
  e = 6.2831853071795862 / (double)nRows;
  n = nRows / 2 / 2;
  emxInit_real_T(&costab1q, 2);
  i = costab1q->size[0] * costab1q->size[1];
  costab1q->size[0] = 1;
  costab1q->size[1] = n + 1;
  emxEnsureCapacity_real_T(costab1q, i);
  costab1q_data = costab1q->data;
  costab1q_data[0] = 1.0;
  nd2 = (int)((unsigned int)n >> 1);
  if (nd2 > 2147483646) {
    check_forloop_overflow_error();
  }
  for (k = 0; k < nd2; k++) {
    costab1q_data[k + 1] = cos(e * ((double)k + 1.0));
  }
  i = nd2 + 1;
  nd2 = n - 1;
  for (k = i; k <= nd2; k++) {
    costab1q_data[k] = sin(e * (double)(n - k));
  }
  costab1q_data[n] = 0.0;
  emxInit_real_T(&costab, 2);
  emxInit_real_T(&sintab, 2);
  if (!useRadix2) {
    n = costab1q->size[1] - 1;
    nd2 = (costab1q->size[1] - 1) << 1;
    i = costab->size[0] * costab->size[1];
    costab->size[0] = 1;
    costab->size[1] = nd2 + 1;
    emxEnsureCapacity_real_T(costab, i);
    b_costab_data = costab->data;
    i = sintab->size[0] * sintab->size[1];
    sintab->size[0] = 1;
    sintab->size[1] = nd2 + 1;
    emxEnsureCapacity_real_T(sintab, i);
    b_sintab_data = sintab->data;
    b_costab_data[0] = 1.0;
    b_sintab_data[0] = 0.0;
    emxInit_real_T(&sintabinv, 2);
    i = sintabinv->size[0] * sintabinv->size[1];
    sintabinv->size[0] = 1;
    sintabinv->size[1] = nd2 + 1;
    emxEnsureCapacity_real_T(sintabinv, i);
    b_sintabinv_data = sintabinv->data;
    for (k = 0; k < n; k++) {
      b_sintabinv_data[k + 1] = costab1q_data[(n - k) - 1];
    }
    i = costab1q->size[1];
    for (k = i; k <= nd2; k++) {
      b_sintabinv_data[k] = costab1q_data[k - n];
    }
    for (k = 0; k < n; k++) {
      b_costab_data[k + 1] = costab1q_data[k + 1];
      b_sintab_data[k + 1] = -costab1q_data[(n - k) - 1];
    }
    i = costab1q->size[1];
    for (k = i; k <= nd2; k++) {
      b_costab_data[k] = -costab1q_data[nd2 - k];
      b_sintab_data[k] = -costab1q_data[k - n];
    }
    costab_size[0] = 1;
    costab_size[1] = costab->size[1];
    nd2 = costab->size[1];
    sintab_size[0] = 1;
    sintab_size[1] = sintab->size[1];
    sintabinv_size[0] = 1;
    sintabinv_size[1] = sintabinv->size[1];
    for (i = 0; i < nd2; i++) {
      costab_data[i] = b_costab_data[i];
      sintab_data[i] = b_sintab_data[i];
      sintabinv_data[i] = b_sintabinv_data[i];
    }
    emxFree_real_T(&sintabinv);
  } else {
    n = costab1q->size[1] - 1;
    nd2 = (costab1q->size[1] - 1) << 1;
    i = costab->size[0] * costab->size[1];
    costab->size[0] = 1;
    costab->size[1] = nd2 + 1;
    emxEnsureCapacity_real_T(costab, i);
    b_costab_data = costab->data;
    i = sintab->size[0] * sintab->size[1];
    sintab->size[0] = 1;
    sintab->size[1] = nd2 + 1;
    emxEnsureCapacity_real_T(sintab, i);
    b_sintab_data = sintab->data;
    b_costab_data[0] = 1.0;
    b_sintab_data[0] = 0.0;
    for (k = 0; k < n; k++) {
      b_costab_data[k + 1] = costab1q_data[k + 1];
      b_sintab_data[k + 1] = -costab1q_data[(n - k) - 1];
    }
    i = costab1q->size[1];
    for (k = i; k <= nd2; k++) {
      b_costab_data[k] = -costab1q_data[nd2 - k];
      b_sintab_data[k] = -costab1q_data[k - n];
    }
    costab_size[0] = 1;
    costab_size[1] = costab->size[1];
    nd2 = costab->size[1];
    sintab_size[0] = 1;
    sintab_size[1] = sintab->size[1];
    for (i = 0; i < nd2; i++) {
      costab_data[i] = b_costab_data[i];
      sintab_data[i] = b_sintab_data[i];
    }
    sintabinv_size[0] = 1;
    sintabinv_size[1] = 0;
  }
  emxFree_real_T(&costab1q);
  emxFree_real_T(&sintab);
  emxFree_real_T(&costab);
}

int c_FFTImplementationCallback_get(int nfft, boolean_T useRadix2, int *nRows)
{
  static rtRunTimeErrorInfo k_emlrtRTEI = {
      417,                                       /* lineNo */
      "FFTImplementationCallback/get_algo_sizes" /* fName */
  };
  int n2blue;
  n2blue = 1;
  if (useRadix2) {
    *nRows = nfft;
  } else {
    int n;
    if (nfft > 0) {
      int pmax;
      n = (nfft + nfft) - 1;
      pmax = 31;
      if (n <= 1) {
        pmax = 0;
      } else {
        int pmin;
        boolean_T exitg1;
        pmin = 0;
        exitg1 = false;
        while ((!exitg1) && (pmax - pmin > 1)) {
          int k;
          int pow2p;
          k = (pmin + pmax) >> 1;
          pow2p = 1 << k;
          if (pow2p == n) {
            pmax = k;
            exitg1 = true;
          } else if (pow2p > n) {
            pmax = k;
          } else {
            pmin = k;
          }
        }
      }
      n2blue = 1 << pmax;
    }
    n = nfft << 2;
    if (n < 1) {
      n = 1;
    }
    if (n2blue > n) {
      rtErrorWithMessageID(k_emlrtRTEI.fName, k_emlrtRTEI.lineNo);
    }
    *nRows = n2blue;
  }
  return n2blue;
}

int c_FFTImplementationCallback_r2b(const double x_data[], int x_size,
                                    int n1_unsigned, const double costab_data[],
                                    const int costab_size[2],
                                    const double sintab_data[],
                                    creal_T y_data[])
{
  emxArray_creal_T *b_y;
  creal_T *b_y_data;
  int i;
  int y_size;
  y_size = n1_unsigned;
  if (n1_unsigned > x_size) {
    memset(&y_data[0], 0, (unsigned int)n1_unsigned * sizeof(creal_T));
  }
  if (n1_unsigned != 1) {
    c_FFTImplementationCallback_doH(x_data, x_size, y_data, &y_size,
                                    n1_unsigned, costab_data, costab_size,
                                    sintab_data);
  } else {
    int y;
    if (x_size <= 1) {
      y = x_size;
    } else {
      y = 1;
    }
    y_data[0].re = x_data[y - 1];
    y_data[0].im = 0.0;
    emxInit_creal_T(&b_y);
    i = b_y->size[0];
    b_y->size[0] = n1_unsigned;
    emxEnsureCapacity_creal_T(b_y, i);
    b_y_data = b_y->data;
    for (i = 0; i < n1_unsigned; i++) {
      b_y_data[i] = y_data[i];
    }
    y_size = b_y->size[0];
    y = b_y->size[0];
    for (i = 0; i < y; i++) {
      y_data[i] = b_y_data[i];
    }
    emxFree_creal_T(&b_y);
  }
  return y_size;
}

void d_FFTImplementationCallback_r2b(const emxArray_creal_T *x,
                                     int unsigned_nRows,
                                     const emxArray_real_T *costab,
                                     const emxArray_real_T *sintab,
                                     emxArray_creal_T *y)
{
  const creal_T *x_data;
  creal_T *y_data;
  const double *costab_data;
  const double *sintab_data;
  double temp_im;
  double temp_re;
  double temp_re_tmp;
  double twid_re;
  int i;
  int iDelta;
  int iDelta2;
  int iheight;
  int ihi;
  int iy;
  int j;
  int ju;
  int k;
  int nRowsD2;
  sintab_data = sintab->data;
  costab_data = costab->data;
  x_data = x->data;
  iy = y->size[0];
  y->size[0] = unsigned_nRows;
  emxEnsureCapacity_creal_T(y, iy);
  y_data = y->data;
  if (unsigned_nRows > x->size[0]) {
    iy = y->size[0];
    y->size[0] = unsigned_nRows;
    emxEnsureCapacity_creal_T(y, iy);
    y_data = y->data;
    for (iy = 0; iy < unsigned_nRows; iy++) {
      y_data[iy].re = 0.0;
      y_data[iy].im = 0.0;
    }
  }
  j = x->size[0];
  if (j > unsigned_nRows) {
    j = unsigned_nRows;
  }
  ihi = unsigned_nRows - 2;
  nRowsD2 = unsigned_nRows / 2;
  k = nRowsD2 / 2;
  iy = 0;
  ju = 0;
  if (j - 1 > 2147483646) {
    check_forloop_overflow_error();
  }
  for (i = 0; i <= j - 2; i++) {
    boolean_T tst;
    y_data[iy] = x_data[i];
    iy = unsigned_nRows;
    tst = true;
    while (tst) {
      iy >>= 1;
      ju ^= iy;
      tst = ((ju & iy) == 0);
    }
    iy = ju;
  }
  y_data[iy] = x_data[j - 1];
  if (unsigned_nRows > 1) {
    for (i = 0; i <= ihi; i += 2) {
      temp_re_tmp = y_data[i + 1].re;
      temp_im = y_data[i + 1].im;
      temp_re = y_data[i].re;
      twid_re = y_data[i].im;
      y_data[i + 1].re = temp_re - temp_re_tmp;
      y_data[i + 1].im = twid_re - temp_im;
      y_data[i].re = temp_re + temp_re_tmp;
      y_data[i].im = twid_re + temp_im;
    }
  }
  iDelta = 2;
  iDelta2 = 4;
  iheight = ((k - 1) << 2) + 1;
  while (k > 0) {
    for (i = 0; i < iheight; i += iDelta2) {
      iy = i + iDelta;
      temp_re = y_data[iy].re;
      temp_im = y_data[iy].im;
      y_data[iy].re = y_data[i].re - temp_re;
      y_data[iy].im = y_data[i].im - temp_im;
      y_data[i].re += temp_re;
      y_data[i].im += temp_im;
    }
    iy = 1;
    for (j = k; j < nRowsD2; j += k) {
      double twid_im;
      twid_re = costab_data[j];
      twid_im = sintab_data[j];
      i = iy;
      ihi = iy + iheight;
      while (i < ihi) {
        ju = i + iDelta;
        temp_re_tmp = y_data[ju].im;
        temp_im = y_data[ju].re;
        temp_re = twid_re * temp_im - twid_im * temp_re_tmp;
        temp_im = twid_re * temp_re_tmp + twid_im * temp_im;
        y_data[ju].re = y_data[i].re - temp_re;
        y_data[ju].im = y_data[i].im - temp_im;
        y_data[i].re += temp_re;
        y_data[i].im += temp_im;
        i += iDelta2;
      }
      iy++;
    }
    k /= 2;
    iDelta = iDelta2;
    iDelta2 += iDelta2;
    iheight -= iDelta;
  }
}

/* End of code generation (FFTImplementationCallback.c) */
