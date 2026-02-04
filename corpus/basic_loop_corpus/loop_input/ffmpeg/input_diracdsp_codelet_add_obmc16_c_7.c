#include <inttypes.h>
#include <stdlib.h>

uint16_t *dst;
uint8_t *src;
uint8_t *obmc_weight;
int x;

void init_vars() {
    size_t num_elements = 16;
    dst = (uint16_t*)aligned_alloc(32, num_elements * sizeof(uint16_t));
    src = (uint8_t*)aligned_alloc(32, num_elements * sizeof(uint8_t));
    obmc_weight = (uint8_t*)aligned_alloc(32, num_elements * sizeof(uint8_t));

    for (size_t i = 0; i < num_elements; i++) {
        dst[i] = 100;
        src[i] = 50;
        obmc_weight[i] = 3;
    }
}