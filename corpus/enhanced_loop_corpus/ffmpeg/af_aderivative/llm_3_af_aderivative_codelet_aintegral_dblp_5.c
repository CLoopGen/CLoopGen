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
        const double *src = s[c];
        double *dst = d[c];
        double *prv = p[c];
        ptrdiff_t stride = 4;
        for (n = 0; n < nb_samples; n += stride) {
            for (int k = 0; k < stride && (n + k) < nb_samples; k++) {
                const double current = src[n + k];
                dst[n + k] = current + prv[0];
                prv[0] = dst[n + k];
            }
        }
    }
}
