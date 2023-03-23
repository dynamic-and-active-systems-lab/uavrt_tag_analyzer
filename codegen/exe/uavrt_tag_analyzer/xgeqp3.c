/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * xgeqp3.c
 *
 * Code generation for function 'xgeqp3'
 *
 */

/* Include files */
#include "xgeqp3.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "uavrt_tag_analyzer_rtwutil.h"
#include "xnrm2.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
int xgeqp3(double A_data[], const int A_size[2], double tau_data[],
           int jpvt_data[], int jpvt_size[2])
{
  double work_data[15];
  int b_k;
  int i;
  int k;
  int loop_ub;
  int n;
  int tau_size;
  n = A_size[1];
  tau_size = A_size[1];
  loop_ub = A_size[1];
  if (loop_ub - 1 >= 0) {
    memset(&tau_data[0], 0, (unsigned int)loop_ub * sizeof(double));
  }
  if (A_size[1] < 1) {
    jpvt_size[0] = 1;
    jpvt_size[1] = A_size[1];
    loop_ub = A_size[1];
    for (k = 0; k < loop_ub; k++) {
      jpvt_data[k] = k + 1;
    }
  } else {
    double vn1_data[15];
    double vn2_data[15];
    double absxk;
    double scale;
    double smax;
    double t;
    int kend;
    int pvt;
    jpvt_size[0] = 1;
    jpvt_size[1] = A_size[1];
    loop_ub = A_size[1];
    for (b_k = 0; b_k < loop_ub; b_k++) {
      jpvt_data[b_k] = b_k + 1;
      work_data[b_k] = 0.0;
      vn1_data[b_k] = 0.0;
      vn2_data[b_k] = 0.0;
      pvt = b_k << 4;
      smax = 0.0;
      scale = 3.3121686421112381E-170;
      kend = pvt + 16;
      for (k = pvt + 1; k <= kend; k++) {
        absxk = fabs(A_data[k - 1]);
        if (absxk > scale) {
          t = scale / absxk;
          smax = smax * t * t + 1.0;
          scale = absxk;
        } else {
          t = absxk / scale;
          smax += t * t;
        }
      }
      absxk = scale * sqrt(smax);
      vn1_data[b_k] = absxk;
      vn2_data[b_k] = absxk;
    }
    for (i = 0; i < n; i++) {
      int b_i;
      int ii;
      int ip1;
      int nmi;
      ip1 = i + 2;
      k = i << 4;
      ii = k + i;
      nmi = n - i;
      if (nmi < 1) {
        kend = -1;
      } else {
        kend = 0;
        if (nmi > 1) {
          smax = fabs(vn1_data[i]);
          for (b_k = 2; b_k <= nmi; b_k++) {
            scale = fabs(vn1_data[(i + b_k) - 1]);
            if (scale > smax) {
              kend = b_k - 1;
              smax = scale;
            }
          }
        }
      }
      pvt = i + kend;
      if (pvt != i) {
        kend = pvt << 4;
        for (b_k = 0; b_k < 16; b_k++) {
          loop_ub = kend + b_k;
          smax = A_data[loop_ub];
          b_i = k + b_k;
          A_data[loop_ub] = A_data[b_i];
          A_data[b_i] = smax;
        }
        kend = jpvt_data[pvt];
        jpvt_data[pvt] = jpvt_data[i];
        jpvt_data[i] = kend;
        vn1_data[pvt] = vn1_data[i];
        vn2_data[pvt] = vn2_data[i];
      }
      t = A_data[ii];
      pvt = ii + 2;
      tau_data[i] = 0.0;
      smax = xnrm2(15 - i, A_data, ii + 2);
      if (smax != 0.0) {
        absxk = A_data[ii];
        scale = rt_hypotd_snf(absxk, smax);
        if (absxk >= 0.0) {
          scale = -scale;
        }
        if (fabs(scale) < 1.0020841800044864E-292) {
          kend = 0;
          b_i = (ii - i) + 16;
          do {
            kend++;
            for (b_k = pvt; b_k <= b_i; b_k++) {
              A_data[b_k - 1] *= 9.9792015476736E+291;
            }
            scale *= 9.9792015476736E+291;
            t *= 9.9792015476736E+291;
          } while ((fabs(scale) < 1.0020841800044864E-292) && (kend < 20));
          smax = xnrm2(15 - i, A_data, ii + 2);
          scale = rt_hypotd_snf(t, smax);
          if (t >= 0.0) {
            scale = -scale;
          }
          tau_data[i] = (scale - t) / scale;
          smax = 1.0 / (t - scale);
          for (b_k = pvt; b_k <= b_i; b_k++) {
            A_data[b_k - 1] *= smax;
          }
          for (b_k = 0; b_k < kend; b_k++) {
            scale *= 1.0020841800044864E-292;
          }
          t = scale;
        } else {
          tau_data[i] = (scale - absxk) / scale;
          smax = 1.0 / (absxk - scale);
          b_i = (ii - i) + 16;
          for (b_k = pvt; b_k <= b_i; b_k++) {
            A_data[b_k - 1] *= smax;
          }
          t = scale;
        }
      }
      A_data[ii] = t;
      if (i + 1 < n) {
        int lastv;
        A_data[ii] = 1.0;
        b_k = ii + 17;
        if (tau_data[i] != 0.0) {
          boolean_T exitg2;
          lastv = 16 - i;
          kend = (ii - i) + 15;
          while ((lastv > 0) && (A_data[kend] == 0.0)) {
            lastv--;
            kend--;
          }
          nmi -= 2;
          exitg2 = false;
          while ((!exitg2) && (nmi + 1 > 0)) {
            int exitg1;
            kend = ii + (nmi << 4);
            loop_ub = kend;
            do {
              exitg1 = 0;
              if (loop_ub + 17 <= (kend + lastv) + 16) {
                if (A_data[loop_ub + 16] != 0.0) {
                  exitg1 = 1;
                } else {
                  loop_ub++;
                }
              } else {
                nmi--;
                exitg1 = 2;
              }
            } while (exitg1 == 0);
            if (exitg1 == 1) {
              exitg2 = true;
            }
          }
        } else {
          lastv = 0;
          nmi = -1;
        }
        if (lastv > 0) {
          if (nmi + 1 != 0) {
            if (nmi >= 0) {
              memset(&work_data[0], 0,
                     (unsigned int)(nmi + 1) * sizeof(double));
            }
            b_i = (ii + (nmi << 4)) + 17;
            for (k = b_k; k <= b_i; k += 16) {
              smax = 0.0;
              pvt = (k + lastv) - 1;
              for (loop_ub = k; loop_ub <= pvt; loop_ub++) {
                smax += A_data[loop_ub - 1] * A_data[(ii + loop_ub) - k];
              }
              kend = ((k - ii) - 17) >> 4;
              work_data[kend] += smax;
            }
          }
          if (!(-tau_data[i] == 0.0)) {
            kend = ii + 17;
            for (k = 0; k <= nmi; k++) {
              absxk = work_data[k];
              if (absxk != 0.0) {
                smax = absxk * -tau_data[i];
                pvt = (lastv + kend) - 1;
                if ((kend <= pvt) && (pvt > 2147483646)) {
                  check_forloop_overflow_error();
                }
                for (loop_ub = kend; loop_ub <= pvt; loop_ub++) {
                  A_data[loop_ub - 1] += A_data[(ii + loop_ub) - kend] * smax;
                }
              }
              kend += 16;
            }
          }
        }
        A_data[ii] = t;
      }
      for (k = ip1; k <= n; k++) {
        kend = i + ((k - 1) << 4);
        absxk = vn1_data[k - 1];
        if (absxk != 0.0) {
          smax = fabs(A_data[kend]) / absxk;
          smax = 1.0 - smax * smax;
          if (smax < 0.0) {
            smax = 0.0;
          }
          scale = absxk / vn2_data[k - 1];
          scale = smax * (scale * scale);
          if (scale <= 1.4901161193847656E-8) {
            absxk = xnrm2(15 - i, A_data, kend + 2);
            vn1_data[k - 1] = absxk;
            vn2_data[k - 1] = absxk;
          } else {
            vn1_data[k - 1] = absxk * sqrt(smax);
          }
        }
      }
    }
  }
  return tau_size;
}

/* End of code generation (xgeqp3.c) */
