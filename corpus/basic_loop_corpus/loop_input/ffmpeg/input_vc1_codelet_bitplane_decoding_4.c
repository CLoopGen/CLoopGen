#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int x;
uint8_t *planep;
int height;
int stride;

void init_vars() {
    height = 1024;
    stride = 1024;
    size_t total_size = (size_t)stride * height;
    planep = (uint8_t *)aligned_alloc(64, total_size);
    if (!planep) {
        exit(1);
    }
    for (size_t i = 0; i < total_size; i++) {
        planep[i] = rand() & 0xFF;
    }
    x = 0;
}