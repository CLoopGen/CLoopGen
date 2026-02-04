#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint16_t *dst;
extern uint16_t *src;
extern  int A;
extern int i;
extern  int E;
extern  ptrdiff_t step;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i += 2) {
    int j;
    for (j = 0; j < 4; j++) {
        dst[j] = ((dst[j] + ((A * src[j] + E * src[step + j]) + 32 >> 6) + 1) >> 1);
    }
    for (j = 0; j < 4; j++) {
        dst[j + stride/sizeof(uint16_t)] = ((dst[j + stride/sizeof(uint16_t)] + 
            ((A * src[j + stride/sizeof(uint16_t)] + E * src[step + j + stride/sizeof(uint16_t)]) + 32 >> 6) + 1) >> 1);
    }
    dst += 2 * stride;
    src += 2 * stride;
}
}
