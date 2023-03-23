/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * levdown.c
 *
 * Code generation for function 'levdown'
 *
 */

/* Include files */
#include "levdown.h"
#include "rt_nonfinite.h"

/* Function Definitions */
int c_binary_expand_op(double in1_data[], const double in2_data[], int in4,
                       int in6, const double in7_data[], const int *in7_size,
                       double in8)
{
  int i;
  int in1_size;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (*in7_size == 1) {
    loop_ub = in6;
  } else {
    loop_ub = *in7_size;
  }
  stride_0_0 = (in6 != 1);
  stride_1_0 = (*in7_size != 1);
  in1_size = loop_ub + 1;
  in1_data[0] = 1.0;
  for (i = 0; i < loop_ub; i++) {
    in1_data[i + 1] = (in2_data[(signed char)in4 + i * stride_0_0] -
                       in7_data[i * stride_1_0]) /
                      (1.0 - in8);
  }
  return in1_size;
}

/* End of code generation (levdown.c) */
