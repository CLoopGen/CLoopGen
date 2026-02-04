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
    for (int outer = 0; outer < 4; outer++) {
        for (int inner = 0; inner < 2; inner++) {
            int offset = inner * 4;
            block[0 + offset] = s1[0 + offset] - s2[0 + offset];
            block[1 + offset] = s1[1 + offset] - s2[1 + offset];
            block[2 + offset] = s1[2 + offset] - s2[2 + offset];
            block[3 + offset] = s1[3 + offset] - s2[3 + offset];
        }
        s1 += stride;
        s2 += stride;
        block += 8;
    }
}
