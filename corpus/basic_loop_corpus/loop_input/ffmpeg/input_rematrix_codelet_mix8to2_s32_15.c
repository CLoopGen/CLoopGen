#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

typedef int integer;

int32_t **out;
int32_t **in;
int *coeffp;
integer len;
int i;

void init_vars() {
    len = 65536; // Size chosen to make loop run ~0.01s on modern CPU

    // Allocate 8 input arrays and 2 output arrays
    in = (int32_t**)calloc(8, sizeof(int32_t*));
    out = (int32_t**)calloc(2, sizeof(int32_t*));
    coeffp = (int*)malloc(16 * sizeof(int)); // At least 2*8 coefficients needed

    for (int j = 0; j < 8; j++) {
        in[j] = (int32_t*)malloc(len * sizeof(int32_t));
        for (int k = 0; k < len; k++) {
            in[j][k] = rand() % 1000 - 500; // Small random values
        }
    }

    for (int j = 0; j < 2; j++) {
        out[j] = (int32_t*)malloc(len * sizeof(int32_t));
        memset(out[j], 0, len * sizeof(int32_t));
    }

    // Initialize coefficients: use meaningful non-zero values
    for (int j = 0; j < 16; j++) {
        coeffp[j] = rand() % 200 - 100;
    }

    i = 0;
}