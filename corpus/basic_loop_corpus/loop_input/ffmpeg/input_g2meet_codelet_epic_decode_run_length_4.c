#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int tile_width = 1000000;
uint32_t *above_row;
int pos;
int start_pos = 0;
uint32_t pix = 42;

void init_vars() {
    above_row = (uint32_t*)calloc(tile_width, sizeof(uint32_t));
    if (!above_row) {
        exit(1);
    }
    for (int i = 0; i < tile_width; i++) {
        above_row[i] = (i < start_pos + 2) ? pix : (i % 1000 == 0 ? pix + 1 : pix);
    }
}