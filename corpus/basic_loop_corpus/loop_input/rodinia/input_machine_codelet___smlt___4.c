#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *dp;
double s;
double *out;
int len;
int i;

static double *dp_storage;
static double *out_storage;

void init_vars() {
    len = 16777216; // 128 MB of doubles (16M * 8 bytes per double)
    dp_storage = (double *)calloc(len, sizeof(double));
    out_storage = (double *)calloc(len, sizeof(double));
    if (!dp_storage || !out_storage) {
        exit(1);
    }
    for (int j = 0; j < len; j++) {
        dp_storage[j] = (double)(j % 1000) / 100.0;
    }
    s = 2.5;
    dp = dp_storage;
    out = out_storage;
}