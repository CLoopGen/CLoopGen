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
    double temp0, temp1, temp2, temp3;
    for (i = 0; i < len; i++) {
        w0 = w[i];
        temp0 = a0 * w0;
        temp1 = a1 * w0;
        temp2 = a2 * w0;
        temp3 = a3 * w0;
        v0[i] += temp0;
        v1[i] += temp1;
        v2[i] += temp2;
        v3[i] += temp3;
    }
}
