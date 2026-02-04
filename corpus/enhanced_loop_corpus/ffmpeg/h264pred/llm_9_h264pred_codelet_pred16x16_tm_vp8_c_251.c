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
for (y = 0; y < 32; y += 2) {
    const uint8_t *cm_in1 = cm + src[-1];
    const uint8_t *cm_in2 = cm + ((src + stride)[-1]);
    for (int i = 0; i < 16; ++i) {
        src[i] = cm_in1[top[i]];
        (src + stride)[i] = cm_in2[top[i]];
    }
    src += 2 * stride;
}
}
