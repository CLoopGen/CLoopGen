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
    for (i = 0; i < channels; i++) {
        mono = pcm[i];
        if (mono != NULL) {
            for (j = 0; j < samples; j++) {
                // Simulated processing: scale sample by factor of 2 if non-negative
                if (mono[j] >= 0.0f) {
                    mono[j] *= 2.0f;
                }
            }
        }
    }
}
