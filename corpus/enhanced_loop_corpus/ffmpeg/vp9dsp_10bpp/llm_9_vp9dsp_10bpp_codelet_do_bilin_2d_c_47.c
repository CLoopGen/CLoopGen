#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern int mx;
extern uint16_t *tmp_ptr;
extern  uint16_t *src;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 1; x < w - 1; x++) {
        uint16_t diff1 = src[x + 1] - src[x];
        uint16_t diff2 = src[x] - src[x - 1];
        uint32_t term1 = mx * diff1;
        uint32_t term2 = mx * diff2;
        tmp_ptr[x] = (src[x] + ((term1 + term2 + 16) >> 5));
    }
}
