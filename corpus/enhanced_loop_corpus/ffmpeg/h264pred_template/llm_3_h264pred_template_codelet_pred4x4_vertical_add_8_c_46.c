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
    // Variant 2: Indirect Memory Access Pattern using index array
    // Use an index lookup table to simulate indirect access to block elements
    const int indices[4] = {0, 4, 8, 12};
    ptrdiff_t offsets[4];
    for (int j = 0; j < 4; j++) {
        offsets[j] = (j + 1) * stride;
    }
    for (i = 0; i < 4; i++) {
        uint8_t v = pix[0];
        v += block[indices[0]];
        pix[offsets[0]] = v;
        v += block[indices[1]];
        pix[offsets[1]] = v;
        v += block[indices[2]];
        pix[offsets[2]] = v;
        v += block[indices[3]];
        pix[offsets[3]] = v;
        pix++;
        block++;
    }
}
