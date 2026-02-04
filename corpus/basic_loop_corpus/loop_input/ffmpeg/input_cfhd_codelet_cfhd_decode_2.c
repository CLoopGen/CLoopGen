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
    size_t data_size = 64 * 1024 * 1024; // ~128 MB of int16_t data (each is 2 bytes)
    run = data_size / sizeof(int16_t);
    data_buffer = (int16_t *)calloc(run, sizeof(int16_t));
    if (!data_buffer) {
        exit(1);
    }
    coeff_data = data_buffer;
    coeff = 42;
}

void cleanup_vars() {
    free(data_buffer);
    data_buffer = NULL;
    coeff_data = NULL;
}