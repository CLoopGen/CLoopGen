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



void loop() {
    for (c = 0; c < channels; c++) {
        const float *src = s[c];
        float *dst = d[c];
        float *prv = p[c];
        for (n = nb_samples - 1; n >= 0; n--) {
            const float current = src[n];
            dst[n] = current + prv[0];
            prv[0] = dst[n];
        }
    }
}
