#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src1;
extern uint8_t *src2;
extern int w1;
extern int w2;
extern ptrdiff_t stride;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < 32; j++) {
    for (i = 0; i < 8; i++) {
        unsigned int val1 = ((unsigned int)w2 * src1[i]) >> 9;
        unsigned int val2 = ((unsigned int)w1 * src2[i]) >> 9;
        unsigned int sum = val1 + val2 + 16;
        dst[i] = sum >> 5;
    }
    src1 += stride;
    src2 += stride;
    dst += stride;
    if (j % 4 == 3) {
        src1 += stride;  
        src2 += stride;  
        dst += stride;   
    }
}
}
