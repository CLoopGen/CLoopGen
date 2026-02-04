#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint8_t *dst;
extern uint8_t *src;
extern  int A;
extern int i;
extern  int E;
extern  int step;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *local_dst = dst;
    uint8_t *local_src = src;
    int accumulated = 0;
    for (i = 0; i < h; i++) {
        accumulated += (((A * local_src[0] + E * local_src[step + 0]) + 32) >> 6);
        local_dst[0] = accumulated & 0xFF;
        local_dst += stride;
        local_src += stride;
    }
}
