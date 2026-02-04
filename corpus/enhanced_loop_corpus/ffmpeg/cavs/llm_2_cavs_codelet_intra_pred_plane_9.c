#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *d;
extern ptrdiff_t stride;
extern int x;
extern int y;
extern int ia;
extern int ih;
extern int iv;
extern  uint8_t *cm;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by precomputing base pointers and using linear indexing
    uint8_t *d_base = d;
    int ia_shifted = (ia + 16) >> 5;
    for (y = 0; y < 8; y++) {
        int row_offset = y * stride;
        int iv_term = (y - 3) * iv;
        for (x = 0; x < 8; x++) {
            int cm_index = ia_shifted + ((x - 3) * ih + iv_term);
            d_base[row_offset + x] = cm[cm_index];
        }
    }
}
