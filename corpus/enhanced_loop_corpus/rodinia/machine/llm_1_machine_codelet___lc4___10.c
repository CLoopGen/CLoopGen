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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < len; i += 4) {
    int end = (i + 4 > len) ? len : i + 4;
    for (int k = i; k < end; k++)
        w[k] += a0 * v0[k] + a1 * v1[k] + a2 * v2[k] + a3 * v3[k];
}
}
