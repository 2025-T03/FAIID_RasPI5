/*
*  main.c
*
*  file created: apr 19, 2026
*  author: Eric Barber
*  description: the main file for the FAIID_RasPI5 project
*  
*/

/* Include files */
#include "main.h"
#include "FFT.h"
#include "FFT_emxAPI.h"
#include "FFT_initialize.h"
#include "FFT_terminate.h"
#include "FFT_types.h"
#include "FormBeam.h"
#include "predictClass.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void argInit_1x1280_real_T(double result[1280]);

static emxArray_real_T *argInit_d2559x16_real_T(void);

static int argInit_d2559x1_real_T(double result_data[]);

static double argInit_real_T(void);

static unsigned char argInit_uint8_T(void);

/* Function Definitions */
/*
 * Arguments    : double result[1280]
 * Return Type  : void
 */
static void argInit_1x1280_real_T(double result[1280])
{
  int idx1;
  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 1280; idx1++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx1] = argInit_real_T();
  }
}

/*
 * Arguments    : void
 * Return Type  : emxArray_real_T *
 */
static emxArray_real_T *argInit_d2559x16_real_T(void)
{
  emxArray_real_T *result;
  double *result_data;
  int idx0;
  int idx1;
  /* Set the size of the array.
Change this size to the value that the application requires. */
  result = emxCreate_real_T(2, 16);
  result_data = result->data;
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    for (idx1 = 0; idx1 < 16; idx1++) {
      /* Set the value of the array element.
Change this value to the value that the application requires. */
      result_data[idx0 + result->size[0] * idx1] = argInit_real_T();
    }
  }
  return result;
}

/*
 * Arguments    : double result_data[]
 * Return Type  : int
 */
static int argInit_d2559x1_real_T(double result_data[])
{
  int idx0;
  int result_size;
  /* Set the size of the array.
Change this size to the value that the application requires. */
  result_size = 2;
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 2; idx0++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result_data[idx0] = argInit_real_T();
  }
  return result_size;
}

/*
 * Arguments    : void
 * Return Type  : double
 */
static double argInit_real_T(void)
{
  return 0.0;
}

/*
 * Arguments    : void
 * Return Type  : unsigned char
 */
static unsigned char argInit_uint8_T(void)
{
  return 0U;
}


int main (){
  return 0;
}
