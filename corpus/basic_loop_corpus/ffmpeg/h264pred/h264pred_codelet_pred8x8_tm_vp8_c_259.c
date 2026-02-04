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
for (y = 0; y < 8; y++) {
    const uint8_t *cm_in = cm + src[-1];
    src[0] = cm_in[top[0]];
    src[1] = cm_in[top[1]];
    src[2] = cm_in[top[2]];
    src[3] = cm_in[top[3]];
    src[4] = cm_in[top[4]];
    src[5] = cm_in[top[5]];
    src[6] = cm_in[top[6]];
    src[7] = cm_in[top[7]];
    src += stride;
}

}
