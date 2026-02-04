#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int16_t *coeff_data;
int run;
int coeff;

static int16_t *data_buffer;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~128 MB of int16_t data (each int16_t is 2 bytes)
    run = data_size / sizeof(int16_t);   // Number of iterations to fill the buffer
    data_buffer = (int16_t *)calloc(run, sizeof(int16_t));
    if (!data_buffer) {
        exit(1);
    }
    coeff_data = data_buffer;
    coeff = 42; // Arbitrary constant value for coeff
    i = 0;
}