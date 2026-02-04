#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>

double *v0;
double *v1;
double *v2;
double *v3;
double *w;
int len;
int i;
double sum00;
double sum10;
double sum20;
double sum30;
double w_val0;

void loop();

void init_vars() {
    len = 4 * 1024 * 1024;  // Approximately 256 MB of input data (4 arrays of doubles)

    v0 = (double *)aligned_alloc(32, len * sizeof(double));
    v1 = (double *)aligned_alloc(32, len * sizeof(double));
    v2 = (double *)aligned_alloc(32, len * sizeof(double));
    v3 = (double *)aligned_alloc(32, len * sizeof(double));
    w  = (double *)aligned_alloc(32, len * sizeof(double));

    for (int j = 0; j < len; j++) {
        v0[j] = 1.0 + j * 0.000001;
        v1[j] = 1.5 + j * 0.000002;
        v2[j] = 2.0 + j * 0.000003;
        v3[j] = 2.5 + j * 0.000004;
        w[j]  = 0.8 + j * 0.0000005;
    }

    sum00 = 0.0;
    sum10 = 0.0;
    sum20 = 0.0;
    sum30 = 0.0;
    w_val0 = 0.0;
    i = 0;
}