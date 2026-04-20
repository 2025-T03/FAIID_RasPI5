/*
 * File: FFT.c
 *
 * MATLAB Coder version            : 25.2
 * C/C++ source code generated on  : 19-Apr-2026 21:11:52
 */

/* Include Files */
#include "FFT.h"
#include "abs.h"
#include "fft1.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
/*
 * function tf = FFT(audioIn)
 *
 * Arguments    : const double audioIn_data[]
 *                const int audioIn_size[1]
 *                double tf_data[]
 *                int tf_size[1]
 * Return Type  : void
 */
void FFT(const double audioIn_data[], const int audioIn_size[1],
         double tf_data[], int tf_size[1])
{
  creal_T x_data[2559];
  double P2_data[2559];
  int audioIn_re;
  int i;
  int i1;
  int x_size;
  /* 'FFT:3' P2 = abs(fft(audioIn)/length(audioIn)); */
  x_size = fft(audioIn_data, audioIn_size[0], x_data);
  audioIn_re = audioIn_size[0];
  for (i = 0; i < x_size; i++) {
    double ai;
    double im;
    double re;
    im = x_data[i].re;
    ai = x_data[i].im;
    if (ai == 0.0) {
      re = im / (double)audioIn_re;
      im = 0.0;
    } else if (im == 0.0) {
      re = 0.0;
      im = ai / (double)audioIn_re;
    } else {
      re = im / (double)audioIn_re;
      im = ai / (double)audioIn_re;
    }
    x_data[i].re = re;
    x_data[i].im = im;
  }
  b_abs(x_data, x_size, P2_data);
  /* 'FFT:4' P1 = P2(1:length(audioIn)/2+1); */
  x_size = (int)((double)audioIn_size[0] / 2.0 + 1.0);
  tf_size[0] = x_size;
  memcpy(&tf_data[0], &P2_data[0], (unsigned int)x_size * sizeof(double));
  /* 'FFT:5' P1(2:end-1) = 2*P1(2:end-1); */
  audioIn_re = (x_size - 1 >= 2);
  if (x_size - 1 < 2) {
    i1 = -1;
    x_size = 1;
  } else {
    i1 = 0;
  }
  x_size = (x_size - i1) - 2;
  for (i = 0; i < x_size; i++) {
    tf_data[(i1 + i) + 1] = 2.0 * P2_data[audioIn_re + i];
  }
  /* 'FFT:6' tf = P1; */
}

/*
 * File trailer for FFT.c
 *
 * [EOF]
 */
