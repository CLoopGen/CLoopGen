#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;

float **out;
float **in;
float *coeffp;
integer len;
int i;

void init_vars() {
    len = 1 << 20; // Approximately 1 million elements for ~0.01 sec runtime

    // Allocate coefficient array (8 coefficients per row, 2 rows needed)
    coeffp = (float*)calloc(16, sizeof(float));
    for (int idx = 0; idx < 16; idx++) {
        coeffp[idx] = (float)(idx + 1) * 0.1f;
    }

    // Allocate input and output arrays: 8 input rows, 2 output rows
    in = (float**)calloc(8, sizeof(float*));
    out = (float**)calloc(2, sizeof(float*));

    for (int row = 0; row < 8; row++) {
        in[row] = (float*)calloc(len, sizeof(float));
        for (int col = 0; col < len; col++) {
            in[row][col] = (float)(rand() % 100) / 10.0f;
        }
    }

    for (int row = 0; row < 2; row++) {
        out[row] = (float*)calloc(len, sizeof(float));
    }
}