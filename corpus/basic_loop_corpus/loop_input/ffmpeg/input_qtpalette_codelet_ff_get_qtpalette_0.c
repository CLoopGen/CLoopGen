#include <stdint.h>
#include <stdlib.h>

uint32_t *palette;
int i;
uint32_t color_count;
uint32_t r;
uint32_t g;
uint32_t b;
int color_index;
int color_dec;

void init_vars() {
    color_count = 65536;
    color_index = 255;
    color_dec = 4;
    palette = (uint32_t*)malloc(color_count * sizeof(uint32_t));
}

void loop();