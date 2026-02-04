#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t (*mask)[8][4];
int row_and_7;
int h;
int y;
int mask_id;
int m_row;

void init_vars() {
    const size_t total_data_size = 16 * 1024 * 1024; // ~16MB to target ~0.01s runtime
    const size_t num_masks = total_data_size / (8 * 4 * sizeof(uint8_t));
    if (num_masks == 0) {
        mask = calloc(1, 8 * 4 * sizeof(uint8_t));
    } else {
        mask = calloc(num_masks, 8 * 4 * sizeof(uint8_t));
    }

    row_and_7 = 0;
    h = 8;
    mask_id = 0;
    m_row = 1;
}
