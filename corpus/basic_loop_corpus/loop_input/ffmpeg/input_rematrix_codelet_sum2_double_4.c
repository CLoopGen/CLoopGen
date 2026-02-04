#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

typedef int integer;

double *out;
double *in1;
double *in2;
integer len;
int i;
double coeff1;
double coeff2;

void init_vars() {
    len = 8000000;

    out = (double*)aligned_alloc(32, len * sizeof(double));
    in1 = (double*)aligned_alloc(32, len * sizeof(double));
    in2 = (double*)aligned_alloc(32, len * sizeof(double));

    for (i = 0; i < len; i++) {
        in1[i] = (double)(rand() % 1000) / 10.0;
        in2[i] = (double)(rand() % 1000) / 10.0;
    }

    coeff1 = 1.25;
    coeff2 = -0.75;

    for (i = 0; i < len; i++) {
        out[i] = 0.0;
    }
}