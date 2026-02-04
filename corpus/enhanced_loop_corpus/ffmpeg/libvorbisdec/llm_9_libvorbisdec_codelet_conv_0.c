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
for (i = 0; i < channels * 2; i += 2) {
    if (i < channels) {
        mono = pcm[i];
        for (j = 0; j < samples; j++) {
            mono[j] += mono[j] * 0.1f;
        }
    }
    if (i + 1 < channels) {
        mono = pcm[i + 1];
        for (j = 0; j < samples; j++) {
            mono[j] -= mono[j] * 0.1f;
        }
    }
}
}
