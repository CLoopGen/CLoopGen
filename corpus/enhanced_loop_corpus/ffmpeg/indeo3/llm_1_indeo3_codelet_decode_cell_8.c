#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct Cell {
    int16_t xpos;
    int16_t ypos;
    int16_t width;
    int16_t height;
    uint8_t tree;
    const int8_t *mv_ptr;
} Cell;

extern uint8_t requant_tab[8][128];
extern Cell *cell;
extern int x;
extern int vq_index;
extern uint8_t *ref_block;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (cell->width > 0) {
        for (x = 0; x < (cell->width << 2); x += 4) {
            ref_block[x]     = requant_tab[vq_index & 7][ref_block[x]     & 127];
            if (x + 1 >= (cell->width << 2)) continue;
            ref_block[x + 1] = requant_tab[vq_index & 7][ref_block[x + 1] & 127];
            if (x + 2 >= (cell->width << 2)) continue;
            ref_block[x + 2] = requant_tab[vq_index & 7][ref_block[x + 2] & 127];
            if (x + 3 >= (cell->width << 2)) continue;
            ref_block[x + 3] = requant_tab[vq_index & 7][ref_block[x + 3] & 127];
        }
    }
}
