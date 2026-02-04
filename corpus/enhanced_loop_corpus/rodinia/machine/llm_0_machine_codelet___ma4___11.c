#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *v0;
extern double *v1;
extern double *v2;
extern double *v3;
extern double *w;
extern int len;
extern int i;
extern double a0;
extern double a1;
extern double a2;
extern double a3;
extern double w0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len; i += 2) {
        w0 = w[i];
        v0[i] += a0 * w0;
        v1[i] += a1 * w0;
        v2[i] += a2 * w0;
        v3[i] += a3 * w0;
        if (i + 1 < len) {
            w0 = w[i + 1];
            v0[i + 1] += a0 * w0;
            v1[i + 1] += a1 * w0;
            v2[i + 1] += a2 * w0;
            v3[i + 1] += a3 * w0;
        }
    }
}
