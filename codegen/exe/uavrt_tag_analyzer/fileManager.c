/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * fileManager.c
 *
 * Code generation for function 'fileManager'
 *
 */

/* Include files */
#include "fileManager.h"
#include "rt_nonfinite.h"
#include "uavrt_tag_analyzer_data.h"
#include "uavrt_tag_analyzer_internal_types.h"
#include <stdio.h>
#include <string.h>

/* Function Declarations */
static signed char filedata(void);

static void u_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

/* Function Definitions */
static signed char filedata(void)
{
  int k;
  signed char f;
  boolean_T exitg1;
  f = 0;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 20)) {
    if (eml_openfiles[k] == NULL) {
      f = (signed char)(k + 1);
      exitg1 = true;
    } else {
      k++;
    }
  }
  return f;
}

static void u_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  fprintf(stderr, "For code generation, maximum number of open files is %d.",
          20);
  fprintf(stderr, "\n");
  fprintf(stderr, "Error in %s (line %d)", aFcnName, aLineNum);
  fprintf(stderr, "\n");
  fflush(stderr);
  abort();
}

signed char cfopen(const char cfilename_data[], const int cfilename_size[2])
{
  static rtRunTimeErrorInfo k_emlrtRTEI = {
      111,     /* lineNo */
      "cfopen" /* fName */
  };
  FILE *filestar;
  char ccfilename_data[201];
  signed char fileid;
  signed char j;
  fileid = -1;
  j = filedata();
  if (j < 1) {
    u_rtErrorWithMessageID(k_emlrtRTEI.fName, k_emlrtRTEI.lineNo);
  } else {
    int loop_ub;
    loop_ub = cfilename_size[1];
    if (loop_ub - 1 >= 0) {
      memcpy(&ccfilename_data[0], &cfilename_data[0],
             (unsigned int)loop_ub * sizeof(char));
    }
    ccfilename_data[cfilename_size[1]] = '\x00';
    filestar = fopen(&ccfilename_data[0], "rb");
    if (filestar != NULL) {
      eml_openfiles[j - 1] = filestar;
      loop_ub = j + 2;
      if (j + 2 > 127) {
        loop_ub = 127;
      }
      fileid = (signed char)loop_ub;
    }
  }
  return fileid;
}

void filedata_init(void)
{
  int i;
  for (i = 0; i < 20; i++) {
    eml_openfiles[i] = NULL;
  }
}

/* End of code generation (fileManager.c) */
