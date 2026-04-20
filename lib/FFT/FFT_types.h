/*
 * File: FFT_types.h
 *
 * MATLAB Coder version            : 25.2
 * C/C++ source code generated on  : 19-Apr-2026 21:11:52
 */

#ifndef FFT_TYPES_H
#define FFT_TYPES_H

/* Include Files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_emxArray_creal_T
#define typedef_emxArray_creal_T
typedef struct {
  creal_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  bool canFreeData;
} emxArray_creal_T;
#endif /* typedef_emxArray_creal_T */

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
struct emxArray_real_T {
  double *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  bool canFreeData;
};
#endif /* struct_emxArray_real_T */
#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T
typedef struct emxArray_real_T emxArray_real_T;
#endif /* typedef_emxArray_real_T */

#ifndef struct_emxArray_char_T_1x13
#define struct_emxArray_char_T_1x13
struct emxArray_char_T_1x13 {
  char data[13];
  int size[2];
};
#endif /* struct_emxArray_char_T_1x13 */
#ifndef typedef_emxArray_char_T_1x13
#define typedef_emxArray_char_T_1x13
typedef struct emxArray_char_T_1x13 emxArray_char_T_1x13;
#endif /* typedef_emxArray_char_T_1x13 */

#ifndef typedef_cell_wrap_10
#define typedef_cell_wrap_10
typedef struct {
  emxArray_char_T_1x13 f1;
} cell_wrap_10;
#endif /* typedef_cell_wrap_10 */

#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T
struct emxArray_int32_T {
  int *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  bool canFreeData;
};
#endif /* struct_emxArray_int32_T */
#ifndef typedef_emxArray_int32_T
#define typedef_emxArray_int32_T
typedef struct emxArray_int32_T emxArray_int32_T;
#endif /* typedef_emxArray_int32_T */

#endif
/*
 * File trailer for FFT_types.h
 *
 * [EOF]
 */
