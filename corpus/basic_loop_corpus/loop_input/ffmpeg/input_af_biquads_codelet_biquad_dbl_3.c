#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int len = 1048576;

double b0 = 0.5;
double b1 = 0.25;
double b2 = 0.125;
double a1 = 0.5;
double a2 = 0.25;
int *clippings = NULL;
int disabled = 0;
double *ibuf = NULL;
double *obuf = NULL;
double i1 = 0.0;
double i2 = 0.0;
double o1 = 0.0;
double o2 = 0.0;
double wet = 0.8;
double dry = 0.2;
double out = 0.0;
int i = 0;

void init_vars() {
    clippings = (int*)calloc(1, sizeof(int));
    ibuf = (double*)aligned_alloc(32, len * sizeof(double));
    obuf = (double*)aligned_alloc(32, len * sizeof(double));

    for (int j = 0; j < len; j++) {
        ibuf[j] = (double)(j % 1000) / 1000.0;
    }

    i1 = 0.0;
    i2 = 0.0;
    o1 = 0.0;
    o2 = 0.0;
    *clippings = 0;
}