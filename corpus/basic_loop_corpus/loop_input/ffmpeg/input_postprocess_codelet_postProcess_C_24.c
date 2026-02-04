#include <stdint.h>
#include <stdlib.h>

uint64_t * yHistogram;
uint64_t sum;
int i;

void init_vars() {
    size_t num_elements = 256;
    yHistogram = (uint64_t*)aligned_alloc(64, num_elements * sizeof(uint64_t));
    for (size_t idx = 0; idx < num_elements; idx++) {
        yHistogram[idx] = (uint64_t)(idx * 31 + 7);
    }
    sum = 0;
    i = 0;
}