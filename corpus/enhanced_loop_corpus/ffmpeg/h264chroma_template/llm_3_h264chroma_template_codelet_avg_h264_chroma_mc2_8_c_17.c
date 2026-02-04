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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *local_dst = dst;
    uint8_t *local_src = src;
    for (i = 0; i < h; i++) {
        for (int j = 0; j < 2; j++) {
            local_dst[j] = (((local_dst[j]) + (((A * local_src[j]) + 32) >> 6) + 1) >> 1);
        }
        local_dst += stride;
        local_src += stride;
    }
}
