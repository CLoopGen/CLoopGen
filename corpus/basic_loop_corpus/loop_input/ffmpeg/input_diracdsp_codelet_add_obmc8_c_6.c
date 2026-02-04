#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t *dst;
uint8_t *src;
uint8_t *obmc_weight;
int x;

void init_vars() {
    size_t data_size = 1 << 20; // 1MB of data to ensure ~0.01s runtime

    dst = (uint16_t*)aligned_alloc(32, data_size * sizeof(uint16_t));
    src = (uint8_t*)aligned_alloc(32, data_size * sizeof(uint8_t));
    obmc_weight = (uint8_t*)aligned_alloc(32, data_size * sizeof(uint8_t));

    for (size_t i = 0; i < data_size; ++i) {
        dst[i] = (uint16_t)(i & 0x3FF);
        src[i] = (uint8_t)((i * 7) & 0xFF);
        obmc_weight[i] = (uint8_t)((i * 13) & 0xFF);
    }
}