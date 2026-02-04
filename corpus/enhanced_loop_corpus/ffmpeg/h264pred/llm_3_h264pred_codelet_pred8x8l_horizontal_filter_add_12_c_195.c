#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint16_t *src;
extern  int32_t *block;
extern uint16_t pix[8];
extern int stride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    uint16_t v = pix[i];
    int idx = i;
    src[stride * 0 + idx] = v += block[8 * 0 + idx];
    src[stride * 1 + idx] = v += block[8 * 1 + idx];
    src[stride * 2 + idx] = v += block[8 * 2 + idx];
    src[stride * 3 + idx] = v += block[8 * 3 + idx];
    src[stride * 4 + idx] = v += block[8 * 4 + idx];
    src[stride * 5 + idx] = v += block[8 * 5 + idx];
    src[stride * 6 + idx] = v += block[8 * 6 + idx];
    src[stride * 7 + idx] = v + block[8 * 7 + idx];
    block += 8;
}
}
