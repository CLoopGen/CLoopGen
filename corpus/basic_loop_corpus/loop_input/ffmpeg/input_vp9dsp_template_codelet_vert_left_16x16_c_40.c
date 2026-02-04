#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *top;
int i;
uint8_t ve[15];
uint8_t vo[15];

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of data
    top = (uint8_t *)malloc(data_size);
    if (!top) {
        exit(1);
    }
    for (size_t idx = 0; idx < data_size; ++idx) {
        top[idx] = (uint8_t)(idx % 256);
    }
}