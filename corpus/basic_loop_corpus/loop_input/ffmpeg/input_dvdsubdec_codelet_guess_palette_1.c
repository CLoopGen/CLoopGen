#include <stdlib.h>
#include <stdint.h>

uint32_t *rgba_palette;
int i;

void init_vars() {
    rgba_palette = (uint32_t*)calloc(4, sizeof(uint32_t));
}

void loop();