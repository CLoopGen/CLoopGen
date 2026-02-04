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
    int shift_width = cell->width << 2;
    for (x = 0; x < shift_width; x++) {
        uint8_t index = ref_block[x] & 127;
        uint8_t table_idx = vq_index & 7;
        if (index < 128 && table_idx < 8) {
            ref_block[x] = requant_tab[table_idx][index];
        } else {
            ref_block[x] = 0;
        }
    }
}
