#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *buf;
extern ptrdiff_t pitch;
extern int16_t tmp[16];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by transposing the loop order and accessing buf in a contiguous manner
    int16_t *row = buf;
    for (i = 0; i < 4; i++) {
        int16_t *col = row;
        for (j = 0; j < 4; j++) {
            col[0] += (tmp[i * 4 + j] >> 1);
            col += pitch; // Strided access down the column, but inner loop now updates one element per row
        }
        row++; // Move to next contiguous column in base row
    }
}
