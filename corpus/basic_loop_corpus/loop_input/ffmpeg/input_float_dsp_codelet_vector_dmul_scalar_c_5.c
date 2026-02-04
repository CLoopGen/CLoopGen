#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stddef.h>

double *dst;
double *src;
double mul;
int len;
int i;

void init_vars() {
    len = 1048576; // Approximately 8MB of data (1M * sizeof(double) * 2)
    dst = (double *)aligned_alloc(32, len * sizeof(double));
    src = (double *)aligned_alloc(32, len * sizeof(double));
    mul = 1.5;
    i = 0;

    for (int j = 0; j < len; j++) {
        src[j] = (double)(j % 1000) / 100.0;
        dst[j] = 0.0;
    }
}

extern void loop();