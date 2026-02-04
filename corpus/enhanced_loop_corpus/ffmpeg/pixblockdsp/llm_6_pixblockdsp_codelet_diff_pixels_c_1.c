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
    int16_t temp[8];
    for (i = 0; i < 8; i++) {
        temp[0] = s1[0] - s2[0];
        temp[1] = s1[1] - s2[1];
        temp[2] = s1[2] - s2[2];
        temp[3] = s1[3] - s2[3];
        temp[4] = s1[4] - s2[4];
        temp[5] = s1[5] - s2[5];
        temp[6] = s1[6] - s2[6];
        temp[7] = s1[7] - s2[7];
        block[0] = temp[0];
        block[1] = temp[1];
        block[2] = temp[2];
        block[3] = temp[3];
        block[4] = temp[4];
        block[5] = temp[5];
        block[6] = temp[6];
        block[7] = temp[7];
        s1 += stride;
        s2 += stride;
        block += 8;
    }
}
