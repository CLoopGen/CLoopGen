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
    // Variant 1: Strided memory access pattern
    // Instead of processing each channel fully before moving to the next,
    // we now access samples in a strided manner across channels (interleaving).
    for (j = 0; j < samples; j++) {
        for (i = 0; i < channels; i++) {
            mono = pcm[i];
            // Access sample j from each channel in sequence
            float sample_val = mono[j]; // Simulated use to maintain realistic access
        }
    }
}
