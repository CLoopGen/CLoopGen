#include <stdlib.h>
#include <stdint.h>

int stride = 8;
int i = 0;
uint16_t *dst;
int32_t *src;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of data
    const size_t num_elements = data_size / sizeof(int32_t);
    const size_t outer_iterations = num_elements / 8;

    src = (int32_t*)aligned_alloc(32, num_elements * sizeof(int32_t));
    dst = (uint16_t*)aligned_alloc(32, outer_iterations * stride * 8 * sizeof(uint16_t));

    for (size_t j = 0; j < num_elements; j++) {
        src[j] = (int32_t)(j % 1000);
    }

    for (size_t j = 0; j < outer_iterations * stride * 8; j++) {
        dst[j] = (uint16_t)(j % 1000);
    }
}