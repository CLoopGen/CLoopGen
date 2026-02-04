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
    len = 16777216; // ~16.7M elements to target ~0.01s runtime with reasonable data size

    // Allocate coefficient array (8 coefficients per row, at least 2 rows needed)
    coeffp = (double*)calloc(16, sizeof(double));
    for (int c = 0; c < 16; c++) {
        coeffp[c] = 1.0 + (c * 0.1);
    }

    // Allocate input and output arrays: in[8][len], out[2][len]
    in = (double**)calloc(8, sizeof(double*));
    out = (double**)calloc(2, sizeof(double*));

    for (int row = 0; row < 8; row++) {
        in[row] = (double*)calloc(len, sizeof(double));
        for (int col = 0; col < len; col++) {
            in[row][col] = (double)(col % 100) + row * 0.01;
        }
    }

    for (int row = 0; row < 2; row++) {
        out[row] = (double*)calloc(len, sizeof(double));
    }
}