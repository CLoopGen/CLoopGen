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
        double prev_val = prv[0];
        for (n = 0; n < nb_samples; n++) {
            const double current = src[n];
            if (n > 0 || channels > 1) {
                dst[n] = current - prev_val;
            } else {
                dst[n] = 0.0;
            }
            prev_val = current;
        }
        prv[0] = prev_val;
    }
}
