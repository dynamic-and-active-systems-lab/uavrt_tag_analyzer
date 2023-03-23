/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * eml_mtimes_helper.c
 *
 * Code generation for function 'eml_mtimes_helper'
 *
 */

/* Include files */
#include "eml_mtimes_helper.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void b_binary_expand_op(double in1_data[], int in1_size[2], double in2,
                        const double in3_data[], const int in3_size[2])
{
  double in2_data[256];
  int aux_0_1;
  int aux_1_1;
  int b_loop_ub;
  int i;
  int i1;
  int loop_ub;
  int stride_0_0;
  int stride_0_1;
  int stride_1_0;
  int stride_1_1;
  if (in3_size[0] == 1) {
    loop_ub = in1_size[0];
  } else {
    loop_ub = in3_size[0];
  }
  if (in3_size[1] == 1) {
    b_loop_ub = in1_size[1];
  } else {
    b_loop_ub = in3_size[1];
  }
  stride_0_0 = (in1_size[0] != 1);
  stride_0_1 = (in1_size[1] != 1);
  stride_1_0 = (in3_size[0] != 1);
  stride_1_1 = (in3_size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      in2_data[i1 + loop_ub * i] =
          in2 * (in1_data[i1 * stride_0_0 + in1_size[0] * aux_0_1] +
                 in3_data[i1 * stride_1_0 + in3_size[0] * aux_1_1]);
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  in1_size[0] = loop_ub;
  in1_size[1] = b_loop_ub;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      in1_data[i1 + in1_size[0] * i] = in2_data[i1 + loop_ub * i];
    }
  }
}

/* End of code generation (eml_mtimes_helper.c) */
