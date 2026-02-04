#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

float *d;
float *x;
int hsize;
int idx;

void init_vars() {
    hsize = 64 * 1024 * 1024 / sizeof(float);  // ~256 MB total for two arrays (d and x)
    d = (float *)calloc(hsize, sizeof(float));
    x = (float *)calloc(hsize, sizeof(float));
    idx = 0;
}