#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *pix;
extern int line_size;
extern int s;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with flattened indexing
    int idx = 0;
    for (i = 0; i < 16; i++) {
        for (j = 0; j < 16; j += 8) {
            s += pix[idx + 0];
            s += pix[idx + 1];
            s += pix[idx + 2];
            s += pix[idx + 3];
            s += pix[idx + 4];
            s += pix[idx + 5];
            s += pix[idx + 6];
            s += pix[idx + 7];
            idx += 8;
        }
        idx += line_size - 16;
    }
}
