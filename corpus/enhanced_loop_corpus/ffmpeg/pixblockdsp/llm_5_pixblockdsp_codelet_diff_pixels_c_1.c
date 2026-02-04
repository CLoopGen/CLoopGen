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
        int offset = (i & 1) ? 4 : 0;
        for (int j = 0; j < 4; j++) {
            block[j + offset] = s1[j + offset] - s2[j + offset];
        }
        s1 += stride;
        s2 += stride;
        block += 8;
    }
}
