#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;

double **out;
double **in;
double *coeffp;
integer len;
int i;

void init_vars() {
    len = 1000000; // Approximately 8MB of input data (1e6 * 8 bytes per double)

    // Allocate coefficient array (at least 2*6 elements based on indexing)
    coeffp = (double*)calloc(12, sizeof(double));
    for (int j = 0; j < 12; j++) {
        coeffp[j] = 1.0 + j * 0.1;
    }

    // Allocate input and output arrays
    in = (double**)calloc(6, sizeof(double*));
    out = (double**)calloc(2, sizeof(double*));

    for (int j = 0; j < 6; j++) {
        in[j] = (double*)calloc(len, sizeof(double));
        for (int k = 0; k < len; k++) {
            in[j][k] = (double)(k % 256) / 256.0;
        }
    }

    for (int j = 0; j < 2; j++) {
        out[j] = (double*)calloc(len, sizeof(double));
    }
}