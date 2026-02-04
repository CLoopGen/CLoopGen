#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t stride;
extern  uint8_t *cm;
extern uint8_t *top;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 16; y += 2) {
    const uint8_t *cm_in1 = cm + src[-1];
    const uint8_t *cm_in2 = cm + src[stride - 1];
    src[0] = cm_in1[top[0]];
    src[1] = cm_in1[top[1]];
    src[2] = cm_in1[top[2]];
    src[3] = cm_in1[top[3]];
    src[4] = cm_in1[top[4]];
    src[5] = cm_in1[top[5]];
    src[6] = cm_in1[top[6]];
    src[7] = cm_in1[top[7]];
    src += stride;
    if (y + 1 < 16) {
        src[0] = cm_in2[top[0]];
        src[1] = cm_in2[top[1]];
        src[2] = cm_in2[top[2]];
        src[3] = cm_in2[top[3]];
        src[4] = cm_in2[top[4]];
        src[5] = cm_in2[top[5]];
        src[6] = cm_in2[top[6]];
        src[7] = cm_in2[top[7]];
        src += stride;
    }
}
}
