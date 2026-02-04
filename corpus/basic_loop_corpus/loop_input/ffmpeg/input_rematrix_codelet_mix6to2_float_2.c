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

    // Allocate 6 input and 2 output row pointers
    in = (float **)calloc(6, sizeof(float*));
    out = (float **)calloc(2, sizeof(float*));

    // Allocate each row with 'len' float elements
    for (int row = 0; row < 6; row++) {
        in[row] = (float *)calloc(len, sizeof(float));
    }
    for (int row = 0; row < 2; row++) {
        out[row] = (float *)calloc(len, sizeof(float));
    }

    coeffp = (float *)calloc(12, sizeof(float)); // At least 2*6 coefficients needed
    for (int k = 0; k < 12; k++) {
        coeffp[k] = 1.0f; // Initialize to 1.0 for meaningful computation
    }
}