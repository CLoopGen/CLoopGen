#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *obmc_weight;
int stride;
int x;

static uint8_t *weight_buffer;

void init_vars() {
    size_t data_size = 128 * 1024 * 1024; // 128 MB for ~0.01 sec runtime
    weight_buffer = calloc(data_size, sizeof(uint8_t));
    if (!weight_buffer) {
        exit(1);
    }
    obmc_weight = weight_buffer;
    stride = data_size - 1;
    x = 0;
}