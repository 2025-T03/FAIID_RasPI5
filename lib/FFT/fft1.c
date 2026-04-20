/*
 * File: fft1.c
 *
 * MATLAB Coder version            : 25.2
 * C/C++ source code generated on  : 19-Apr-2026 21:11:52
 */

/* Include Files */
#include "fft1.h"
#include "FFTImplementationCallback.h"
#include "FFT_emxutil.h"
#include "FFT_types.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : const double x_data[]
 *                int x_size
 *                creal_T y_data[]
 * Return Type  : int
 */
int fft(const double x_data[], int x_size, creal_T y_data[])
{
  emxArray_creal_T *y;
  emxArray_real_T *costab;
  emxArray_real_T *costab1q;
  emxArray_real_T *sintab;
  emxArray_real_T *sintabinv;
  creal_T *b_y_data;
  double *costab1q_data;
  double *costab_data;
  double *sintab_data;
  double *sintabinv_data;
  int k;
  int nd2;
  int y_size;
  emxInit_creal_T(&y);
  b_y_data = y->data;
  if (x_size == 0) {
    y->size[0] = 0;
  } else {
    double e;
    int b_n2;
    int n;
    int n2;
    bool useRadix2;
    useRadix2 = (((unsigned int)x_size & (unsigned int)(x_size - 1)) == 0U);
    n2 = 1;
    if (useRadix2) {
      nd2 = x_size;
    } else {
      y_size = (x_size + x_size) - 1;
      nd2 = 31;
      if (y_size <= 1) {
        nd2 = 0;
      } else {
        bool exitg1;
        n = 0;
        exitg1 = false;
        while ((!exitg1) && (nd2 - n > 1)) {
          n2 = (n + nd2) >> 1;
          b_n2 = 1 << n2;
          if (b_n2 == y_size) {
            nd2 = n2;
            exitg1 = true;
          } else if (b_n2 > y_size) {
            nd2 = n2;
          } else {
            n = n2;
          }
        }
      }
      n2 = 1 << nd2;
      nd2 = n2;
    }
    e = 6.2831853071795862 / (double)nd2;
    n = (int)(((unsigned int)nd2 >> 1) >> 1);
    emxInit_real_T(&costab1q, 2);
    nd2 = costab1q->size[0] * costab1q->size[1];
    costab1q->size[0] = 1;
    costab1q->size[1] = n + 1;
    emxEnsureCapacity_real_T(costab1q, nd2);
    costab1q_data = costab1q->data;
    costab1q_data[0] = 1.0;
    nd2 = (int)((unsigned int)n >> 1) - 1;
    for (k = 0; k <= nd2; k++) {
      costab1q_data[k + 1] = cos(e * ((double)k + 1.0));
    }
    y_size = nd2 + 2;
    for (k = y_size; k < n; k++) {
      costab1q_data[k] = sin(e * (double)(n - k));
    }
    costab1q_data[n] = 0.0;
    emxInit_real_T(&costab, 2);
    emxInit_real_T(&sintab, 2);
    emxInit_real_T(&sintabinv, 2);
    if (!useRadix2) {
      nd2 = costab1q->size[1] - 1;
      b_n2 = (costab1q->size[1] - 1) << 1;
      y_size = costab->size[0] * costab->size[1];
      costab->size[0] = 1;
      costab->size[1] = b_n2 + 1;
      emxEnsureCapacity_real_T(costab, y_size);
      costab_data = costab->data;
      y_size = sintab->size[0] * sintab->size[1];
      sintab->size[0] = 1;
      sintab->size[1] = b_n2 + 1;
      emxEnsureCapacity_real_T(sintab, y_size);
      sintab_data = sintab->data;
      costab_data[0] = 1.0;
      sintab_data[0] = 0.0;
      y_size = sintabinv->size[0] * sintabinv->size[1];
      sintabinv->size[0] = 1;
      sintabinv->size[1] = b_n2 + 1;
      emxEnsureCapacity_real_T(sintabinv, y_size);
      sintabinv_data = sintabinv->data;
      for (k = 0; k < nd2; k++) {
        sintabinv_data[k + 1] = costab1q_data[(nd2 - k) - 1];
      }
      y_size = costab1q->size[1];
      for (k = y_size; k <= b_n2; k++) {
        sintabinv_data[k] = costab1q_data[k - nd2];
      }
      for (k = 0; k < nd2; k++) {
        costab_data[k + 1] = costab1q_data[k + 1];
        sintab_data[k + 1] = -costab1q_data[(nd2 - k) - 1];
      }
      for (k = y_size; k <= b_n2; k++) {
        costab_data[k] = -costab1q_data[b_n2 - k];
        sintab_data[k] = -costab1q_data[k - nd2];
      }
      c_FFTImplementationCallback_dob(x_data, x_size, n2, x_size, costab,
                                      sintab, sintabinv, y);
      b_y_data = y->data;
    } else {
      n = costab1q->size[1] - 1;
      n2 = (costab1q->size[1] - 1) << 1;
      nd2 = costab->size[0] * costab->size[1];
      costab->size[0] = 1;
      costab->size[1] = n2 + 1;
      emxEnsureCapacity_real_T(costab, nd2);
      costab_data = costab->data;
      nd2 = sintab->size[0] * sintab->size[1];
      sintab->size[0] = 1;
      sintab->size[1] = n2 + 1;
      emxEnsureCapacity_real_T(sintab, nd2);
      sintab_data = sintab->data;
      costab_data[0] = 1.0;
      sintab_data[0] = 0.0;
      for (k = 0; k < n; k++) {
        costab_data[k + 1] = costab1q_data[k + 1];
        sintab_data[k + 1] = -costab1q_data[(n - k) - 1];
      }
      y_size = costab1q->size[1];
      for (k = y_size; k <= n2; k++) {
        costab_data[k] = -costab1q_data[n2 - k];
        sintab_data[k] = -costab1q_data[k - n];
      }
      nd2 = y->size[0];
      y->size[0] = x_size;
      emxEnsureCapacity_creal_T(y, nd2);
      b_y_data = y->data;
      if (x_size != 1) {
        c_FFTImplementationCallback_doH(x_data, x_size, y, x_size, costab,
                                        sintab);
        b_y_data = y->data;
      } else {
        b_y_data[0].re = x_data[0];
        b_y_data[0].im = 0.0;
      }
    }
    emxFree_real_T(&sintabinv);
    emxFree_real_T(&sintab);
    emxFree_real_T(&costab);
    emxFree_real_T(&costab1q);
  }
  nd2 = y->size[0];
  y_size = y->size[0];
  for (k = 0; k < nd2; k++) {
    y_data[k] = b_y_data[k];
  }
  emxFree_creal_T(&y);
  return y_size;
}

/*
 * File trailer for fft1.c
 *
 * [EOF]
 */
