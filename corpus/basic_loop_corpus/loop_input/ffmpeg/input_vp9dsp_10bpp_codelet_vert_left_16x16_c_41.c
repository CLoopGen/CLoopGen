#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t *top;
int i;
uint16_t ve[15];
uint16_t vo[15];

void init_vars() {
    size_t data_size = 128 * 1024 * 1024 / sizeof(uint16_t);
    top = (uint16_t*)aligned_alloc(_Alignof(uint16_t), data_size * sizeof(uint16_t));
    for (size_t j = 0; j < data_size; j++) {
        top[j] = (uint16_t)(j % 32768);
    }
}