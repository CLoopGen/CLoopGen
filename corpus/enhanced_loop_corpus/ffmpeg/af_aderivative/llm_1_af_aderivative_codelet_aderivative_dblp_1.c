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
if (channels > 0 && nb_samples > 0) {
    for (c = 0; c < channels; c++) {
        const double *src = s[c];
        double *dst = d[c];
        double *prv = p[c];
        const double current = src[0];
        dst[0] = current - prv[0];
        prv[0] = current;
    }
    for (n = 1; n < nb_samples; n++) {
        for (c = 0; c < channels; c++) {
            const double *src = s[c];
            double *dst = d[c];
            double *prv = p[c];
            const double current = src[n];
            dst[n] = current - prv[0];
            prv[0] = current;
        }
    }
}
}
