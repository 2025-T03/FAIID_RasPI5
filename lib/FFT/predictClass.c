/*
 * File: predictClass.c
 *
 * MATLAB Coder version            : 25.2
 * C/C++ source code generated on  : 19-Apr-2026 21:11:52
 */

/* Include Files */
#include "predictClass.h"
#include "CompactClassificationNeuralNetwork.h"
#include "FFT_internal_types.h"
#include "FFT_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * function class = predictClass(data)
 *
 * Arguments    : const double data[1280]
 *                cell_wrap_10 class_data[]
 *                int class_size[1]
 * Return Type  : void
 */
void predictClass(const double data[1280], cell_wrap_10 class_data[],
                  int class_size[1])
{
  double expl_temp[5];
  int mdl_ClassNamesLength[5];
  bool b_expl_temp[5];
  /* 'predictClass:2' mdl = loadLearnerForCoder("compactFAIID.mat"); */
  c_CompactClassificationNeuralNe(mdl_ClassNamesLength, expl_temp, b_expl_temp);
  /* 'predictClass:3' class = predict(mdl,data); */
  class_size[0] =
      d_CompactClassificationNeuralNe(mdl_ClassNamesLength, data, class_data);
}

/*
 * File trailer for predictClass.c
 *
 * [EOF]
 */
