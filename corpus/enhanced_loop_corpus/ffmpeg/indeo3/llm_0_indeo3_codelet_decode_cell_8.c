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
    for (int i = 0; i < cell->width; i++) {
        for (x = 0; x < 4; x++) {
            int idx = (i << 2) + x;
            ref_block[idx] = requant_tab[vq_index & 7][ref_block[idx] & 127];
        }
    }
}
