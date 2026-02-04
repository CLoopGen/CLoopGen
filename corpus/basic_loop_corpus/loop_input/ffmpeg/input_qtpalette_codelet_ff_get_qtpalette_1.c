#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint32_t *palette;
int i;
uint32_t color_count;
uint32_t r;
uint32_t g;
uint32_t b;
uint8_t *color_table;

void init_vars() {
    color_count = 6710886;  // 6710886 colors * 3 bytes = ~20.1 MB input data, ~0.01 sec estimate
    color_table = (uint8_t*)malloc(color_count * 3 * sizeof(uint8_t));
    palette = (uint32_t*)malloc(color_count * sizeof(uint32_t));

    for (uint32_t idx = 0; idx < color_count * 3; idx++) {
        color_table[idx] = (uint8_t)(idx % 256);
    }
}