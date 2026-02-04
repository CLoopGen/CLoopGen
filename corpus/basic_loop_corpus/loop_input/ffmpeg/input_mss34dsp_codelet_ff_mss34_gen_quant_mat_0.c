#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t *qmat;
int i;
uint8_t *qsrc;
int scale;

void init_vars() {
    size_t array_size = 64;

    qmat = (uint16_t *)calloc(array_size, sizeof(uint16_t));
    qsrc = (uint8_t *)malloc(array_size * sizeof(uint8_t));

    for (size_t idx = 0; idx < array_size; idx++) {
        qsrc[idx] = (uint8_t)((idx * 7) % 251);
    }

    scale = 150;
}

__attribute__((constructor)) void constructor_call() {
    init_vars();
}