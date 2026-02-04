#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

double *in;
double *window;
int in_len;
int i;

void init_vars() {
    in_len = 16777216; // 128 MB of data (16M * 8 bytes per double)

    in = (double*)aligned_alloc(32, in_len * sizeof(double));
    window = (double*)aligned_alloc(32, in_len * sizeof(double));

    if (!in || !window) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < in_len; j++) {
        in[j] = 1.0 + (j % 1000) * 1e-4;
        window[j] = 0.5 + (j % 1500) * 1e-4;
    }

    i = 0;
}