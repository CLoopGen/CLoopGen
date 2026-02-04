#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int w;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i = x;
    uint8_t *local_dst = dst;
    uint8_t *local_src = src;
    for (; i < w; i++) {
        local_dst[i + 1] = local_src[(i >> 1)]; // Introduce WAW dependency via offset write
        local_dst[i] = local_src[(i >> 1)];
    }
    x = i;
}
