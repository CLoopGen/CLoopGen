#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern void **d;
extern void **p;
extern  void **s;
extern int nb_samples;
extern int channels;
extern int n;
extern int c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
float *temp_dst = malloc(channels * nb_samples * sizeof(float));
float *temp_prv = malloc(channels * sizeof(float));

for (c = 0; c < channels; c++) {
    temp_prv[c] = ((float**)p)[c][0];
}

for (n = 0; n < nb_samples; n++) {
    for (c = 0; c < channels; c++) {
        const float current = ((float**)s)[c][n];
        float *dst = ((float**)d)[c];
        dst[n] = current + temp_prv[c];
        temp_prv[c] = dst[n];
    }
}

free(temp_dst);
free(temp_prv);
}
