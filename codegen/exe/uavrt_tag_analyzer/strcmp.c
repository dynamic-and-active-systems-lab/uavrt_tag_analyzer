/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * strcmp.c
 *
 * Code generation for function 'strcmp'
 *
 */

/* Include files */
#include "strcmp.h"
#include "rt_nonfinite.h"

/* Function Definitions */
boolean_T b_strcmp(const char a_data[], const int a_size[2])
{
  static const char cv[3] = {'a', 'l', 'l'};
  boolean_T b_bool;
  b_bool = false;
  if (a_size[1] == 3) {
    int kstr;
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 3) {
        if (a_data[kstr] != cv[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return b_bool;
}

/* End of code generation (strcmp.c) */
