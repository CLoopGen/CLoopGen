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
for (y = 0; y < 16; y++) {
    const uint8_t *cm_in = cm + src[-1];
    src[0] = cm_in[top[0]];
    src[1] = cm_in[top[1]];
    src[2] = cm_in[top[2]];
    src[3] = cm_in[top[3]];
    src[4] = cm_in[top[4]];
    src[5] = cm_in[top[5]];
    src[6] = cm_in[top[6]];
    src[7] = cm_in[top[7]];
    src[8] = cm_in[top[8]];
    src[9] = cm_in[top[9]];
    src[10] = cm_in[top[10]];
    src[11] = cm_in[top[11]];
    src[12] = cm_in[top[12]];
    src[13] = cm_in[top[13]];
    src[14] = cm_in[top[14]];
    src[15] = cm_in[top[15]];
    src += stride;
}

}
