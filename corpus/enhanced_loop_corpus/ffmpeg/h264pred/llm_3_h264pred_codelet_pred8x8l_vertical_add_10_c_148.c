#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern uint16_t *pix;
extern  int32_t *block;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Use indirect array indexing via precomputed index array to simulate irregular access pattern
    static const int indices[8] = {0, 8, 16, 24, 32, 40, 48, 56};
    for (i = 0; i < 8; i++) {
        uint16_t v = pix[0];
        // Strided write remains, but block is accessed through indirect indexing
        pix[1 * stride] = v += block[indices[0]];
        pix[2 * stride] = v += block[indices[1]];
        pix[3 * stride] = v += block[indices[2]];
        pix[4 * stride] = v += block[indices[3]];
        pix[5 * stride] = v += block[indices[4]];
        pix[6 * stride] = v += block[indices[5]];
        pix[7 * stride] = v += block[indices[6]];
        pix[8 * stride] = v + block[indices[7]];
        pix++;
        block++; // block advances by 1 each time, but indexing is indirect
    }
}
