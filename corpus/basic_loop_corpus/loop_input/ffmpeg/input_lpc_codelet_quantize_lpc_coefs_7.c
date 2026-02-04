#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *lpc_in;
int order;
int i;
double scale;

void init_vars() {
    order = 131072; // Approximately 1MB of double data (131072 * 8 bytes)
    scale = 1.5;
    lpc_in = (double*)aligned_alloc(32, order * sizeof(double));
    if (!lpc_in) {
        exit(1);
    }
    for (int j = 0; j < order; j++) {
        lpc_in[j] = (double)(j % 1000) / 100.0;
    }
}