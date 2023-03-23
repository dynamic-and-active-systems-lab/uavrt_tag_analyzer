/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * fread.c
 *
 * Code generation for function 'fread'
 *
 */

/* Include files */
#include "fread.h"
#include "rt_nonfinite.h"
#include "uavrt_tag_analyzer_data.h"
#include "uavrt_tag_analyzer_emxutil.h"
#include "uavrt_tag_analyzer_internal_types.h"
#include "uavrt_tag_analyzer_types.h"
#include <stddef.h>
#include <stdio.h>

/* Function Declarations */
static void e_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void f_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void g_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

/* Function Definitions */
static void e_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  fprintf(stderr, "Invalid file identifier. Use fopen to generate a valid file "
                  "identifier.");
  fprintf(stderr, "\n");
  fprintf(stderr, "Error in %s (line %d)", aFcnName, aLineNum);
  fprintf(stderr, "\n");
  fflush(stderr);
  abort();
}

static void f_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  fprintf(stderr, "Invalid file identifier.  Use fopen to generate a valid "
                  "file identifier.");
  fprintf(stderr, "\n");
  fprintf(stderr, "Error in %s (line %d)", aFcnName, aLineNum);
  fprintf(stderr, "\n");
  fflush(stderr);
  abort();
}

static void g_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  fprintf(stderr,
          "Operation is not implemented for requested file identifier.");
  fprintf(stderr, "\n");
  fprintf(stderr, "Error in %s (line %d)", aFcnName, aLineNum);
  fprintf(stderr, "\n");
  fflush(stderr);
  abort();
}

void b_fread(double fileID, emxArray_real_T *A)
{
  static rtRunTimeErrorInfo k_emlrtRTEI = {
      147,          /* lineNo */
      "getfilestar" /* fName */
  };
  static rtRunTimeErrorInfo l_emlrtRTEI = {
      72,     /* lineNo */
      "fread" /* fName */
  };
  static rtRunTimeErrorInfo m_emlrtRTEI = {
      297,                    /* lineNo */
      "cast_and_validate_fid" /* fName */
  };
  static rtRunTimeErrorInfo n_emlrtRTEI = {
      494,          /* lineNo */
      "getFileStar" /* fName */
  };
  FILE *f;
  FILE *filestar;
  size_t nBytes;
  double *A_data;
  int i1;
  signed char fileid;
  if ((!(fileID != 0.0)) || (!(fileID != 1.0)) || (!(fileID != 2.0))) {
    g_rtErrorWithMessageID(l_emlrtRTEI.fName, l_emlrtRTEI.lineNo);
  }
  nBytes = sizeof(float);
  fileid = (signed char)fileID;
  if (fileID != (signed char)fileID) {
    e_rtErrorWithMessageID(m_emlrtRTEI.fName, m_emlrtRTEI.lineNo);
  }
  if ((int)fileID != (signed char)fileID) {
    fileid = -1;
  }
  if (fileid >= 3) {
    filestar = eml_openfiles[fileid - 3];
    f = filestar;
    if (filestar == NULL) {
      f_rtErrorWithMessageID(k_emlrtRTEI.fName, k_emlrtRTEI.lineNo);
    }
  } else if (fileid == 0) {
    f = stdin;
  } else if (fileid == 1) {
    f = stdout;
  } else if (fileid == 2) {
    f = stderr;
  } else {
    f = NULL;
  }
  filestar = f;
  if (f == NULL) {
    e_rtErrorWithMessageID(n_emlrtRTEI.fName, n_emlrtRTEI.lineNo);
  }
  if ((!(fileID != 0.0)) || (!(fileID != 1.0)) || (!(fileID != 2.0))) {
    filestar = NULL;
  }
  A->size[0] = 0;
  if (!(filestar == NULL)) {
    int c;
    c = 1;
    while (c > 0) {
      float tbuf[1024];
      int i;
      int numRead;
      c = 0;
      numRead = 1;
      while ((c < 1024) && (numRead > 0)) {
        size_t numReadSizeT;
        numReadSizeT = fread(&tbuf[c], nBytes, (size_t)(1024 - c), filestar);
        numRead = (int)numReadSizeT;
        c += (int)numReadSizeT;
      }
      if (c < 1) {
        numRead = 0;
      } else {
        numRead = c;
      }
      i = A->size[0];
      i1 = A->size[0];
      A->size[0] += numRead;
      emxEnsureCapacity_real_T(A, i1);
      A_data = A->data;
      for (i1 = 0; i1 < numRead; i1++) {
        A_data[i + i1] = tbuf[i1];
      }
    }
  }
}

/* End of code generation (fread.c) */
