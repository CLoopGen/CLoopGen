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
    int stride = 4;
    for (i = 0; i < len; i++) {
        double temp_w = w[i];
        double scaled = a0 * temp_w;
        v0[i] += scaled;
        v1[i] += a1 * temp_w + scaled;
        v2[i] += a2 * temp_w + scaled;
        v3[i] += a3 * temp_w + scaled;
    }
    for (i = 0; i < len; i++) {
        v0[i] *= 1.0 + 1e-10;
        v1[i] *= 1.0 + 1e-10;
    }
}
