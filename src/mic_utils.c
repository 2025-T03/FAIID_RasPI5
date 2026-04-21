/*
*  mic_utils.c
*
*  file created: apr 19, 2026
*  author: Eric Barber
*  description: This file contains several utilities for accessing the FAIID microphone array
*  
*/

/* Include files */
#include "../include/mic_utils.h"
//#include "FFT.h"
//#include "FFT_emxAPI.h"
//#include "FFT_initialize.h"
//#include "FFT_terminate.h"
//#include "FormBeam.h"
//#include "predictClass.h"
//#include "rt_nonfinite.h"

//#define PCM_DEVICE "default" // Change to your I2S device name

int init_i2s(snd_pcm_t *handle, char* PCM_DEVICE){
    snd_pcm_hw_params_t *params;
    unsigned int rate = 44100; // Sample rate
    int dir;
    int rc;
    fprintf(stderr, "in init func\n");
    
	// Open PCM device for reading
    if ((rc = snd_pcm_open(&handle, PCM_DEVICE, SND_PCM_STREAM_CAPTURE, 0)) < 0) {
        fprintf(stderr, "unable to open pcm device: %s\n", snd_strerror(rc));
        return 1;
    }
    fprintf(stderr, "PCM device opened\n");

    // Allocate hardware parameters
    snd_pcm_hw_params_alloca(&params);
    snd_pcm_hw_params_any(handle, params);
    snd_pcm_hw_params_set_access(handle, params, SND_PCM_ACCESS_RW_INTERLEAVED);
    snd_pcm_hw_params_set_format(handle, params, SND_PCM_FORMAT_S16_LE);
    snd_pcm_hw_params_set_rate_near(handle, params, &rate, &dir);
    snd_pcm_hw_params_set_channels(handle, params, 2); // Stereo
    
    fprintf(stderr, "hardware parameters\n");

    // Apply hardware parameters
    if ((rc = snd_pcm_hw_params(handle, params)) < 0) {
        fprintf(stderr, "unable to set hw parameters: %s\n", snd_strerror(rc));
        return 1;
    }
    fprintf(stderr, "applied parameters\n");
    return 0;
}

void read_mic_array(emxArray_real_T *micArray, snd_pcm_t *handle){
    int rc;
    fprintf(stderr, "in read func\n");
	// Read audio data
    char *buffer = malloc(128 * 4); // Buffer for 128 samples
    fprintf(stderr, "memory allocated\n");
    while (1) {
        rc = snd_pcm_readi(handle, buffer, 128);
        if (rc == -EPIPE) {
            fprintf(stderr, "overrun occurred\n");
            snd_pcm_prepare(handle);
        } else if (rc < 0) {
            fprintf(stderr, "error from read: %s\n", snd_strerror(rc));
        } else {
            // Process audio data in buffer
            fprintf(stderr, "mics read\n");
            fprintf(stderr, "raw audio:\n");
            for(int i=0; i<128; i++){
				printf("%d, ", buffer[i]);
			}
        }
    }
}

int main (){
	snd_pcm_t *handle;
	emxArray_real_T *micArray;
	init_i2s(handle, "default");	// Change to your I2S device name
	read_mic_array(micArray, handle);
	return 0;
}
