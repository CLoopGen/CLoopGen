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
int i_start = 0;
int i_end = len2;
for (i = i_start; i < i_end; i += 2) {
    if (i + 1 < len2) {
        tmp0 = w[2 * i] + a0 * v0[2 * i];
        tmp1 = w[2 * i + 1] + a0 * v0[2 * i + 1];
        tmp0 += a1 * v1[2 * i];
        tmp1 += a1 * v1[2 * i + 1];
        tmp0 += a2 * v2[2 * i];
        tmp1 += a2 * v2[2 * i + 1];
        tmp0 += a3 * v3[2 * i];
        tmp1 += a3 * v3[2 * i + 1];
        w[2 * i] = tmp0;
        w[2 * i + 1] = tmp1;

        tmp0 = w[2 * (i + 1)] + a0 * v0[2 * (i + 1)];
        tmp1 = w[2 * (i + 1) + 1] + a0 * v0[2 * (i + 1) + 1];
        tmp0 += a1 * v1[2 * (i + 1)];
        tmp1 += a1 * v1[2 * (i + 1) + 1];
        tmp0 += a2 * v2[2 * (i + 1)];
        tmp1 += a2 * v2[2 * (i + 1) + 1];
        tmp0 += a3 * v3[2 * (i + 1)];
        tmp1 += a3 * v3[2 * (i + 1) + 1];
        w[2 * (i + 1)] = tmp0;
        w[2 * (i + 1) + 1] = tmp1;
    } else {
        tmp0 = w[2 * i] + a0 * v0[2 * i];
        tmp1 = w[2 * i + 1] + a0 * v0[2 * i + 1];
        tmp0 += a1 * v1[2 * i];
        tmp1 += a1 * v1[2 * i + 1];
        tmp0 += a2 * v2[2 * i];
        tmp1 += a2 * v2[2 * i + 1];
        tmp0 += a3 * v3[2 * i];
        tmp1 += a3 * v3[2 * i + 1];
        w[2 * i] = tmp0;
        w[2 * i + 1] = tmp1;
    }
}
}
