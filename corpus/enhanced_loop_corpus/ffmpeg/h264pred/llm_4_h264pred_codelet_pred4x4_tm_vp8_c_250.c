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
for (y = 0; y < 4; y++) {
    if (y % 2 == 0) {
        const uint8_t *cm_in = cm + src[-1];
        src[0] = cm_in[top[0]];
        src[1] = cm_in[top[1]];
        src[2] = cm_in[top[2]];
        src[3] = cm_in[top[3]];
    }
    src += stride;
}
}
