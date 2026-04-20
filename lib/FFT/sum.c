/*
 * File: sum.c
 *
 * MATLAB Coder version            : 25.2
 * C/C++ source code generated on  : 19-Apr-2026 21:11:52
 */

/* Include Files */
#include "sum.h"
#include "FFT_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const emxArray_real_T *x
 *                double y_data[]
 * Return Type  : int
 */
int sum(const emxArray_real_T *x, double y_data[])
{
  const double *x_data;
  int b_xj;
  int xj;
  int y_size;
  x_data = x->data;
  if (x->size[0] == 0) {
    y_size = 0;
  } else {
    int vstride;
    vstride = x->size[0];
    y_size = x->size[0];
    for (xj = 0; xj < vstride; xj++) {
      y_data[xj] = x_data[xj];
    }
    for (xj = 0; xj < 15; xj++) {
      int xoffset;
      xoffset = (xj + 1) * vstride;
      for (b_xj = 0; b_xj < vstride; b_xj++) {
        y_data[b_xj] += x_data[xoffset + b_xj];
      }
    }
  }
  return y_size;
}

/*
 * File trailer for sum.c
 *
 * [EOF]
 */
