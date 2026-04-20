/*
 * File: abs.c
 *
 * MATLAB Coder version            : 25.2
 * C/C++ source code generated on  : 19-Apr-2026 21:11:52
 */

/* Include Files */
#include "abs.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : const creal_T x_data[]
 *                int x_size
 *                double y_data[]
 * Return Type  : int
 */
int b_abs(const creal_T x_data[], int x_size, double y_data[])
{
  int k;
  int y_size;
  y_size = x_size;
  for (k = 0; k < x_size; k++) {
    double a;
    double b;
    a = fabs(x_data[k].re);
    b = fabs(x_data[k].im);
    if (a < b) {
      a /= b;
      y_data[k] = b * sqrt(a * a + 1.0);
    } else if (a > b) {
      b /= a;
      y_data[k] = a * sqrt(b * b + 1.0);
    } else if (rtIsNaN(b)) {
      y_data[k] = rtNaN;
    } else {
      y_data[k] = a * 1.4142135623730951;
    }
  }
  return y_size;
}

/*
 * File trailer for abs.c
 *
 * [EOF]
 */
