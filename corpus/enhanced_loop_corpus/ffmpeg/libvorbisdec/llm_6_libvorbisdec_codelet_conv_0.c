#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int samples;
extern float **pcm;
extern int channels;
extern int i;
extern int j;
extern float *mono;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float *temp_memo[channels];
    for (i = 0; i < channels; i++) {
        temp_memo[i] = pcm[i];
    }
    for (i = 0; i < channels; i++) {
        mono = temp_memo[i];
        for (j = 0; j < samples; j++) {
            mono[j] *= 2.0f;
        }
    }
}
