#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t (*mask)[8][4];
extern int row_and_7;
extern int h;
extern int y;
extern int m_row_16;
extern int m_row_8;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by flattening the 3D array indexing into a stride-based linear pattern
    uint8_t *mask_base = &mask[0][row_and_7][0];
    int height = h;
    for (int i = 0; i < height; i++) {
        mask_base[i * 4 + 0] |= m_row_16;  // equivalent to mask[0][y][0]
        mask_base[i * 4 + 1] |= m_row_8;   // equivalent to mask[0][y][1]
    }
}
