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
    for (i = 0; i < len2; i += 2) {
        for (int j = 0; j < 2 && (i + j) < len2; j++) {
            int idx = i + j;
            tmp0 = w[2 * idx] + a0 * v0[2 * idx];
            tmp1 = w[2 * idx + 1] + a0 * v0[2 * idx + 1];
            tmp0 += a1 * v1[2 * idx];
            tmp1 += a1 * v1[2 * idx + 1];
            tmp0 += a2 * v2[2 * idx];
            tmp1 += a2 * v2[2 * idx + 1];
            tmp0 += a3 * v3[2 * idx];
            tmp1 += a3 * v3[2 * idx + 1];
            w[2 * idx] = tmp0;
            w[2 * idx + 1] = tmp1;
        }
    }
}
