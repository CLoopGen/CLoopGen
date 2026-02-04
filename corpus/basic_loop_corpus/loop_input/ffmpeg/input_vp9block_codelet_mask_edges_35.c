#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t (*mask)[8][4];
int row_and_7;
int h;
int y;
int m_row_16;
int m_row_8;

void init_vars() {
    const int total_data_size = 16 * 1024 * 1024; // ~16 MB to ensure sufficient runtime
    const int num_masks = total_data_size / (8 * 4 * sizeof(uint8_t));
    
    uint8_t (*temp_mask) = aligned_alloc(32, num_masks * 8 * 4 * sizeof(uint8_t));
    for (int i = 0; i < num_masks * 8 * 4; i++) {
        temp_mask[i] = 0;
    }
    mask = (uint8_t(*)[8][4])temp_mask;

    row_and_7 = 0;
    h = 8;
    m_row_16 = 0xAA;
    m_row_8 = 0x55;
}