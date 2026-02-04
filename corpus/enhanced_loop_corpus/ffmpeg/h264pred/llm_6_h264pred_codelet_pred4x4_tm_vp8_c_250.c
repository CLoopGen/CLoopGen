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
    uint8_t val0 = top[0];
    uint8_t val1 = top[1];
    uint8_t val2 = top[2];
    uint8_t val3 = top[3];
    const uint8_t *cm_in = cm + src[-1];
    src[0] = cm_in[val0];
    src[1] = cm_in[val1];
    src[2] = cm_in[val2];
    src[3] = cm_in[val3];
    src += stride;
}
}
