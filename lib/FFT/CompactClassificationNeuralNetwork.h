/*
 * File: CompactClassificationNeuralNetwork.h
 *
 * MATLAB Coder version            : 25.2
 * C/C++ source code generated on  : 19-Apr-2026 21:11:52
 */

#ifndef COMPACTCLASSIFICATIONNEURALNETWORK_H
#define COMPACTCLASSIFICATIONNEURALNETWORK_H

/* Include Files */
#include "FFT_internal_types.h"
#include "FFT_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
c_classreg_learning_coderutils_
c_CompactClassificationNeuralNe(int this_ClassNamesLength[5],
                                double this_Prior[5],
                                bool this_ClassLogicalIndices[5]);

int d_CompactClassificationNeuralNe(const int this_ClassNamesLength[5],
                                    const double Xin[1280],
                                    cell_wrap_10 labels_data[]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for CompactClassificationNeuralNetwork.h
 *
 * [EOF]
 */
