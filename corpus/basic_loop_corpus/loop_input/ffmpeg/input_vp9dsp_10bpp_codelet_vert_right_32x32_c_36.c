#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t *top;
int i;
uint16_t ve[47];
uint16_t vo[47];

void init_vars() {
    size_t data_size = 131072; // 256KB of uint16_t data (131072 * 2 = 262144 bytes)
    top = (uint16_t*)aligned_alloc(_Alignof(uint16_t), data_size * sizeof(uint16_t));
    if (!top) exit(1);
    for (size_t idx = 0; idx < data_size; ++idx) {
        top[idx] = (uint16_t)(idx % 65535);
    }
    for (int idx = 0; idx < 47; ++idx) {
        ve[idx] = 0;
        vo[idx] = 0;
    }
    i = 0;
}