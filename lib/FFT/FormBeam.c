/*
 * File: FormBeam.c
 *
 * MATLAB Coder version            : 25.2
 * C/C++ source code generated on  : 19-Apr-2026 21:11:52
 */

/* Include Files */
#include "FormBeam.h"
#include "FFT_types.h"
#include "delayseq.h"
#include "rt_nonfinite.h"
#include "sum.h"

/* Function Definitions */
/*
 * function micSum = FormBeam(delayIndex, micArray)
 *
 * Arguments    : unsigned char delayIndex
 *                emxArray_real_T *micArray
 *                double micSum_data[]
 *                int micSum_size[1]
 * Return Type  : void
 */
void FormBeam(unsigned char delayIndex, emxArray_real_T *micArray,
              double micSum_data[], int micSum_size[1])
{
  double tmp_data[2559];
  double *micArray_data;
  int b_i;
  int i;
  (void)delayIndex;
  micArray_data = micArray->data;
  /* 'FormBeam:2' micCount = 16; */
  /* 'FormBeam:3' micFs = 96000; */
  /* 'FormBeam:4' delayTbl = [1 2; 3 4; 5 6]; */
  /* 'FormBeam:6' for i = 1:micCount */
  for (i = 0; i < 16; i++) {
    int loop_ub;
    int micArray_size;
    /* 'FormBeam:7' delayt = delayTbl(delayIndex, i); */
    /* 'FormBeam:8' micseq = micArray(:,i); */
    /* 'FormBeam:9' micArray(:,i) = delayseq(micseq,-delayt,micFs); */
    loop_ub = micArray->size[0];
    micArray_size = micArray->size[0];
    delayseq(micArray_size, tmp_data);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      micArray_data[b_i + micArray->size[0] * i] = tmp_data[b_i];
    }
  }
  /* 'FormBeam:11' micSum = sum(micArray,2); */
  micSum_size[0] = sum(micArray, micSum_data);
}

/*
 * File trailer for FormBeam.c
 *
 * [EOF]
 */
