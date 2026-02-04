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
    const uint8_t *cm_in = cm + src[-1];
    if (top[0] >= 16 || top[1] >= 16 || top[2] >= 16 || top[3] >= 16) {
        continue;
    }
    src[0] = cm_in[top[0]];
    src[1] = cm_in[top[1]];
    src[2] = cm_in[top[2]];
    src[3] = cm_in[top[3]];
    src += stride;
}
}
