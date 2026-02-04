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
    for (i = 0; i < len; i++) {
        double temp = 0.0;
        if (v0[i] >= 0) {
            temp += a0 * v0[i];
        }
        if (v1[i] >= 0) {
            temp += a1 * v1[i];
        }
        if (v2[i] >= 0) {
            temp += a2 * v2[i];
        }
        if (v3[i] >= 0) {
            temp += a3 * v3[i];
        }
        w[i] += temp;
    }
}
