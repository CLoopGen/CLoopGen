#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
enum TwinVQFrameType {
    TWINVQ_FT_SHORT = 0,
    TWINVQ_FT_MEDIUM,
    TWINVQ_FT_LONG,
    TWINVQ_FT_PPC
};


extern int16_t *tab;
extern int num_vect;
extern int num_blocks;
extern int block_size;
extern  uint8_t line_len[2];
extern enum TwinVQFrameType ftype;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < line_len[0]; i++) {
        int shift;
        if (num_blocks == 1 || (ftype == TWINVQ_FT_LONG && num_vect % num_blocks) || (ftype != TWINVQ_FT_LONG && num_vect & 1) || i == line_len[1]) {
            shift = 0;
        } else if (ftype == TWINVQ_FT_LONG) {
            shift = i;
        } else {
            shift = i * i;
        }
        for (j = 0; j < num_vect; j++) {
            if (j + num_vect * i >= block_size * num_blocks) break;
            tab[i * num_vect + j] = i * num_vect + (j + shift) % num_vect;
        }
    }
}
