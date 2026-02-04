#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t *left;
int i;
uint16_t ve[47];
uint16_t vo[47];

void init_vars() {
    const size_t total_size = 1 << 20;
    const size_t num_elements = total_size / sizeof(uint16_t);
    
    left = (uint16_t*)aligned_alloc(32, total_size);
    if (!left) exit(1);

    for (size_t idx = 0; idx < num_elements; ++idx) {
        left[idx] = (uint16_t)(idx * idx + 31) & 0xFFFF;
    }

    for (int j = 0; j < 47; ++j) {
        ve[j] = 0;
        vo[j] = 0;
    }
}