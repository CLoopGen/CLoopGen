#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t (*mask)[8][4];
int row_and_7;
int h;
int y;
int t;
int mask_id;

void init_vars() {
    const size_t total_size = 1 << 20; // ~1MB of data
    const size_t num_masks = total_size / (8 * 4 * sizeof(uint8_t));
    
    mask = calloc(num_masks, 8 * 4 * sizeof(uint8_t));
    if (!mask) exit(1);

    row_and_7 = 0;
    h = 8;
    t = 0xFF;
    mask_id = 0;
}

__attribute__((constructor))
static void constructor() {
    init_vars();
}