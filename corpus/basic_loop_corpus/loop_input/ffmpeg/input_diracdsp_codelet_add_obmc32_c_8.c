#include <stdint.h>
#include <stdlib.h>

uint16_t *dst;
uint8_t *src;
uint8_t *obmc_weight;
int x;

void init_vars() {
    size_t data_size = 1 << 20; // 1MB of data

    dst = (uint16_t*)aligned_alloc(32, data_size * sizeof(uint16_t));
    src = (uint8_t*)aligned_alloc(32, data_size * sizeof(uint8_t));
    obmc_weight = (uint8_t*)aligned_alloc(32, data_size * sizeof(uint8_t));

    for (size_t i = 0; i < data_size; i++) {
        dst[i] = rand() % 1000;
        src[i] = rand() % 256;
        obmc_weight[i] = rand() % 256;
    }
}