#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint32_t *pal;
int i;
uint8_t *palette;

void init_vars() {
    pal = (uint32_t*)malloc(64 * sizeof(uint32_t));
    palette = (uint8_t*)malloc(96 * sizeof(uint8_t));
    for (int j = 0; j < 96; ++j) {
        palette[j] = rand() % 256;
    }
}

__attribute__((constructor))
static void constructor() {
    init_vars();
}