/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * main.c
 *
 * Code generation for function 'main'
 *
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

/* Include files */
#include "main.h"
#include "rt_nonfinite.h"
#include "uavrt_tag_analyzer.h"
#include "uavrt_tag_analyzer_terminate.h"
#include "uavrt_tag_analyzer_types.h"
#include <stdio.h>

/* Function Declarations */
static void argInit_1xd200_char_T(char result_data[], int result_size[2]);

static char argInit_char_T(void);

static double argInit_real_T(void);

static void t_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

/* Function Definitions */
static void argInit_1xd200_char_T(char result_data[], int result_size[2])
{
  int idx1;
  /* Set the size of the array.
Change this size to the value that the application requires. */
  result_size[0] = 1;
  result_size[1] = 2;
  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 2; idx1++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result_data[idx1] = argInit_char_T();
  }
}

static char argInit_char_T(void)
{
  return '?';
}

static double argInit_real_T(void)
{
  return 0.0;
}



int main(int argc, char **argv)
{

  /*(void)argv;*/
  
    
    double FsRaw = strtof(argv[1],NULL);
    double pulseDur = strtof(argv[2],NULL);
    double centerFreqMHz = strtof(argv[3],NULL);
    char *path = argv[4];
    
    
    
  main_uavrt_tag_analyzer(FsRaw, pulseDur, centerFreqMHz, path);
  /* Terminate the application.
You do not need to do this more than one time. */
  uavrt_tag_analyzer_terminate();
  return 0;
}

void main_uavrt_tag_analyzer(double FsRaw, double pulseDuration, double radioCenterFreqMHz, char filePath_data[])
{
 
  int filePath_size[2];
  /*char filePath_data[200];*/
  int strLength;
  for (strLength = 0; filePath_data[strLength] != '\0'; ++strLength)
  filePath_size[0] = 1;
  filePath_size[1] = strLength;
  
  /* Call the entry-point 'uavrt_tag_analyzer'. */
  uavrt_tag_analyzer(FsRaw, pulseDuration, radioCenterFreqMHz, filePath_data, filePath_size);
}

/* End of code generation (main.c) */
