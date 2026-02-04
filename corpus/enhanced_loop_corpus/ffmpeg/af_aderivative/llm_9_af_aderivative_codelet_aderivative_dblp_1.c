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
    const double *src = s[c];
    double *dst = d[c];
    double *prv = p[c];
    int step = 2;
    for (n = 0; n < nb_samples - 1; n += step) {
        const double current1 = src[n];
        const double current2 = src[n + 1];
        dst[n] = current1 - prv[0];
        dst[n + 1] = current2 - current1;
        prv[0] = current2;
    }
    if (n == nb_samples - 1) {
        const double current = src[n];
        dst[n] = current - prv[0];
        prv[0] = current;
    }
}
}
