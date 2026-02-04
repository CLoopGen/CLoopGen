#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *v0;
extern double *v1;
extern double *v2;
extern double *v3;
extern double *w;
extern int i;
extern int len2;
extern double a0;
extern double a1;
extern double a2;
extern double a3;
extern double tmp0;
extern double tmp1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < len2; i++) {
    tmp0 = w[2 * i];
    tmp1 = w[2 * i + 1];

    if (v0[2 * i] != 0.0 || v0[2 * i + 1] != 0.0) {
        tmp0 += a0 * v0[2 * i];
        tmp1 += a0 * v0[2 * i + 1];
    }

    if (v1[2 * i] != 0.0 || v1[2 * i + 1] != 0.0) {
        tmp0 += a1 * v1[2 * i];
        tmp1 += a1 * v1[2 * i + 1];
    }

    if (v2[2 * i] != 0.0 || v2[2 * i + 1] != 0.0) {
        tmp0 += a2 * v2[2 * i];
        tmp1 += a2 * v2[2 * i + 1];
    }

    if (v3[2 * i] != 0.0 || v3[2 * i + 1] != 0.0) {
        tmp0 += a3 * v3[2 * i];
        tmp1 += a3 * v3[2 * i + 1];
    }

    w[2 * i] = tmp0;
    w[2 * i + 1] = tmp1;
}
}
