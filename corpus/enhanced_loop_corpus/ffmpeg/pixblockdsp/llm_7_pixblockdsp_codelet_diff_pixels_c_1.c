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
    for (i = 0; i < 8; i++) {
        int16_t val = s1[0] - s2[0];
        block[0] = val;
        block[1] = val + (s1[1] - s2[1]) - val;
        block[2] = val + (s1[2] - s2[2]) - val;
        block[3] = val + (s1[3] - s2[3]) - val;
        block[4] = val + (s1[4] - s2[4]) - val;
        block[5] = val + (s1[5] - s2[5]) - val;
        block[6] = val + (s1[6] - s2[6]) - val;
        block[7] = val + (s1[7] - s2[7]) - val;
        s1 += stride;
        s2 += stride;
        block += 8;
    }
}
