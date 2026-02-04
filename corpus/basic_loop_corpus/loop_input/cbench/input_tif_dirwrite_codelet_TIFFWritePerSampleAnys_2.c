#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

double v = 3.141592653589793;

double *w;
int i;
int samples = 16777216; // ~128MB of data (16M * 8 bytes)

void init_vars() {
    w = (double*)malloc(samples * sizeof(double));
    if (!w) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}