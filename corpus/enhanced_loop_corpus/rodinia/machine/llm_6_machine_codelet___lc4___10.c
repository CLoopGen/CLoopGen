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
    double temp0, temp1, temp2, temp3;
    for (i = 0; i < len; i++) {
        temp0 = a0 * v0[i];
        temp1 = a1 * v1[i];
        temp2 = a2 * v2[i];
        temp3 = a3 * v3[i];
        w[i] += temp0 + temp1 + temp2 + temp3;
    }
}
