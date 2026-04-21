/*
*  mic_utils.h
*  
*  created: apr 20, 2026
*  author: Eric Barber
*  description: this is the header file for mic_utils.c
*/

/*----includes-----*/
#ifndef MAIN_H
#define MAIN_H

/* Include Files */
#include "../lib/FFT/rtwtypes.h"
#include "../lib/FFT/FFT_types.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <alsa/asoundlib.h>

#ifdef __cplusplus
extern "C" {
#endif


/*-----Function Definitions-----*/
int init_i2s(snd_pcm_t *handle, char* PCM_DEVICE);

void read_mic_array(emxArray_real_T *micArray, snd_pcm_t *handle);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for main.h
 *
 * [EOF]
 */
