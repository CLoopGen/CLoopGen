#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t *qmat;
int quality;
int i;
uint8_t *qsrc;

void init_vars() {
    size_t array_size = 64;

    qmat = (uint16_t *)aligned_alloc(32, array_size * sizeof(uint16_t));
    qsrc = (uint8_t *)aligned_alloc(32, array_size * sizeof(uint8_t));

    for (size_t idx = 0; idx < array_size; idx++) {
        qsrc[idx] = (uint8_t)((idx * 17) % 251);
    }

    quality = 50;
    i = 0;

    for (size_t idx = 0; idx < array_size; idx++) {
        qmat[idx] = 0;
    }
}