/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * mldivide.c
 *
 * Code generation for function 'mldivide'
 *
 */

/* Include files */
#include "mldivide.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "uavrt_tag_analyzer_internal_types.h"
#include "xgeqp3.h"
#include <math.h>
#include <stdio.h>
#include <string.h>

/* Function Declarations */
static void k_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

/* Function Definitions */
static void k_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  fprintf(stderr, "Matrix dimensions must agree.");
  fprintf(stderr, "\n");
  fprintf(stderr, "Error in %s (line %d)", aFcnName, aLineNum);
  fprintf(stderr, "\n");
  fflush(stderr);
  abort();
}

int mldivide(const double A_data[], const int A_size[2], const double B_data[],
             double Y_data[])
{
  static rtRunTimeErrorInfo k_emlrtRTEI = {
      16,        /* lineNo */
      "mldivide" /* fName */
  };
  double b_A_data[256];
  double c_A_data[240];
  double b_B_data[16];
  double tau_data[15];
  int jpvt_data[15];
  int b_A_size[2];
  int Y_size;
  int i;
  int j;
  int jp1j;
  int k;
  int rankA;
  if (A_size[0] != 16) {
    k_rtErrorWithMessageID(k_emlrtRTEI.fName, k_emlrtRTEI.lineNo);
  }
  if (A_size[1] == 0) {
    Y_size = 0;
  } else if (A_size[1] == 16) {
    double tol;
    int i1;
    int yk;
    signed char ipiv_data[16];
    memcpy(&b_A_data[0], &A_data[0], 256U * sizeof(double));
    memcpy(&b_B_data[0], &B_data[0], 16U * sizeof(double));
    ipiv_data[0] = 1;
    yk = 1;
    for (k = 0; k < 15; k++) {
      yk++;
      ipiv_data[k + 1] = (signed char)yk;
    }
    for (j = 0; j < 15; j++) {
      int a;
      int b_tmp;
      b_tmp = j * 17;
      jp1j = b_tmp + 2;
      yk = 16 - j;
      a = 0;
      tol = fabs(b_A_data[b_tmp]);
      for (k = 2; k <= yk; k++) {
        double s;
        s = fabs(b_A_data[(b_tmp + k) - 1]);
        if (s > tol) {
          a = k - 1;
          tol = s;
        }
      }
      if (b_A_data[b_tmp + a] != 0.0) {
        if (a != 0) {
          a += j;
          ipiv_data[j] = (signed char)(a + 1);
          for (k = 0; k < 16; k++) {
            yk = k << 4;
            rankA = j + yk;
            tol = b_A_data[rankA];
            i1 = a + yk;
            b_A_data[rankA] = b_A_data[i1];
            b_A_data[i1] = tol;
          }
        }
        i1 = (b_tmp - j) + 16;
        for (i = jp1j; i <= i1; i++) {
          b_A_data[i - 1] /= b_A_data[b_tmp];
        }
      }
      i1 = 14 - j;
      yk = b_tmp + 18;
      for (rankA = 0; rankA <= i1; rankA++) {
        tol = b_A_data[(b_tmp + (rankA << 4)) + 16];
        if (tol != 0.0) {
          a = (yk - j) + 14;
          if ((yk <= a) && (a > 2147483646)) {
            check_forloop_overflow_error();
          }
          for (jp1j = yk; jp1j <= a; jp1j++) {
            b_A_data[jp1j - 1] += b_A_data[((b_tmp + jp1j) - yk) + 1] * -tol;
          }
        }
        yk += 16;
      }
    }
    for (i = 0; i < 15; i++) {
      signed char b_i;
      b_i = ipiv_data[i];
      if (b_i != i + 1) {
        tol = b_B_data[i];
        b_B_data[i] = b_B_data[b_i - 1];
        b_B_data[b_i - 1] = tol;
      }
    }
    for (k = 0; k < 16; k++) {
      yk = k << 4;
      if (b_B_data[k] != 0.0) {
        i1 = k + 2;
        for (i = i1; i < 17; i++) {
          b_B_data[i - 1] -= b_B_data[k] * b_A_data[(i + yk) - 1];
        }
      }
    }
    for (k = 15; k >= 0; k--) {
      yk = k << 4;
      tol = b_B_data[k];
      if (tol != 0.0) {
        tol /= b_A_data[k + yk];
        b_B_data[k] = tol;
        for (i = 0; i < k; i++) {
          b_B_data[i] -= b_B_data[k] * b_A_data[i + yk];
        }
      }
    }
    Y_size = 16;
    memcpy(&Y_data[0], &b_B_data[0], 16U * sizeof(double));
  } else {
    double tol;
    int jpvt_size[2];
    int i1;
    int yk;
    b_A_size[0] = 16;
    b_A_size[1] = A_size[1];
    yk = 16 * A_size[1];
    memcpy(&c_A_data[0], &A_data[0], (unsigned int)yk * sizeof(double));
    xgeqp3(c_A_data, b_A_size, tau_data, jpvt_data, jpvt_size);
    rankA = 0;
    if (b_A_size[1] > 0) {
      tol = 3.5527136788005009E-14 * fabs(c_A_data[0]);
      while ((rankA < b_A_size[1]) &&
             (!(fabs(c_A_data[rankA + 16 * rankA]) <= tol))) {
        rankA++;
      }
    }
    memcpy(&b_B_data[0], &B_data[0], 16U * sizeof(double));
    Y_size = b_A_size[1];
    yk = b_A_size[1];
    for (j = 0; j < yk; j++) {
      Y_data[j] = 0.0;
      if (tau_data[j] != 0.0) {
        tol = b_B_data[j];
        i1 = j + 2;
        for (i = i1; i < 17; i++) {
          tol += c_A_data[(i + 16 * j) - 1] * b_B_data[i - 1];
        }
        tol *= tau_data[j];
        if (tol != 0.0) {
          b_B_data[j] -= tol;
          for (i = i1; i < 17; i++) {
            b_B_data[i - 1] -= c_A_data[(i + 16 * j) - 1] * tol;
          }
        }
      }
    }
    for (i = 0; i < rankA; i++) {
      Y_data[jpvt_data[i] - 1] = b_B_data[i];
    }
    for (j = rankA; j >= 1; j--) {
      i1 = jpvt_data[j - 1];
      yk = 16 * (j - 1);
      Y_data[i1 - 1] /= c_A_data[(j + yk) - 1];
      for (i = 0; i <= j - 2; i++) {
        int a;
        a = jpvt_data[i];
        Y_data[a - 1] -= Y_data[i1 - 1] * c_A_data[i + yk];
      }
    }
  }
  return Y_size;
}

/* End of code generation (mldivide.c) */
