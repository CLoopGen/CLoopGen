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
    for (n = 0; n < nb_samples; n += 2) {
        const double current0 = src[n];
        dst[n] = current0 - prv[0];
        prv[0] = current0;
        if (n + 1 < nb_samples) {
            const double current1 = src[n + 1];
            dst[n + 1] = current1 - prv[0];
            prv[0] = current1;
        }
    }
}
}
