#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern uint8_t *pix;
extern  int16_t *block;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of strided access on `pix`, accumulate values into a local array and write consecutively.
    uint8_t temp[4];
    for (i = 0; i < 4; i++) {
        uint8_t v = pix[0];
        v += block[0];
        temp[0] = v;
        v += block[4];
        temp[1] = v;
        v += block[8];
        temp[2] = v;
        v += block[12];
        temp[3] = v;
        // Write to pix with stride in a consecutive manner
        for (int j = 0; j < 4; j++) {
            ((uint8_t*)pix)[(j + 1) * stride] = temp[j];
        }
        pix++;
        block++;
    }
}
