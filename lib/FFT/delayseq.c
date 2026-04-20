/*
 * File: delayseq.c
 *
 * MATLAB Coder version            : 25.2
 * C/C++ source code generated on  : 19-Apr-2026 21:11:52
 */

/* Include Files */
#include "delayseq.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : int x_size
 *                double y_data[]
 * Return Type  : int
 */
int delayseq(int x_size, double y_data[])
{
  int y_size;
  frexp(2.0 * (double)x_size, &y_size);
  y_size = x_size;
  if (x_size - 1 >= 0) {
    memset(&y_data[0], 0, (unsigned int)x_size * sizeof(double));
  }
  return y_size;
}

/*
 * File trailer for delayseq.c
 *
 * [EOF]
 */
