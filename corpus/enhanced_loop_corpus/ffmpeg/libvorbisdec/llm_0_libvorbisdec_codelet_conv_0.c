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
        for (j = 0; j < samples; j++) {
            // Dummy operation to ensure inner loop is not optimized away
            asm volatile("" : "+r"(mono[j]) : : "memory");
        }
    }
}
