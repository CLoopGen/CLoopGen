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
for (c = 0; c < channels; c++) {
    const float *src = s[c];
    float *dst = d[c];
    float *prv = p[c];
    float prev_val = prv[0];
    for (n = 0; n < nb_samples; n++) {
        const float current = src[n];
        const float diff1 = current - prev_val;
        const float diff2 = diff1 * diff1;
        const float diff3 = diff2 + 0.001f;
        dst[n] = diff3;
        prev_val = current;
    }
    prv[0] = prev_val;
}
}
