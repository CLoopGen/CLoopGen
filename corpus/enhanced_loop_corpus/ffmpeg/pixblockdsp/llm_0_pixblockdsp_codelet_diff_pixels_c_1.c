#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *restrict block;
extern  uint8_t *s1;
extern  uint8_t *s2;
extern ptrdiff_t stride;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < 2; outer++) {
        for (int inner = 0; inner < 4; inner++) {
            int idx = inner;
            block[0] = s1[0] - s2[0];
            block[1] = s1[1] - s2[1];
            block[2] = s1[2] - s2[2];
            block[3] = s1[3] - s2[3];
            s1 += stride;
            s2 += stride;
            block += 4;
        }
        // Adjust block pointer back by 4*8 - 4*4 to maintain original progression
        // Correction: previous step advanced block by 4*4=16 elements, but we need only +8 per outer 8-element row
        // This version instead splits the 8 iterations into two groups of 4
    }
}
