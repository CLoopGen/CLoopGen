#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

uint8_t *flags;
int i;
int32_t *src;
int32_t *dst;
int t0;
int t1;
int t2;
int t3;
int t4;
int t5;
int t6;
int t7;
int t8;

void init_vars() {
    const size_t data_size = 1 << 20; // ~1MB of input data (262,144 elements)
    const size_t num_elements = data_size / sizeof(int32_t);
    
    flags = (uint8_t*)aligned_alloc(64, num_elements * sizeof(uint8_t));
    src = (int32_t*)aligned_alloc(64, (num_elements + 56) * sizeof(int32_t)); 
    dst = (int32_t*)aligned_alloc(64, (num_elements + 56) * sizeof(int32_t));

    for (size_t idx = 0; idx < num_elements; ++idx) {
        flags[idx] = (rand() % 2); 
    }

    for (size_t idx = 0; idx < num_elements + 56; ++idx) {
        src[idx] = rand() % 1000 - 500;
        dst[idx] = 0;
    }
}