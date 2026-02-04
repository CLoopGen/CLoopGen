#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *pix;
extern int line_size;
extern int s;
extern int i;
extern int j;
extern  uint32_t *sq;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 16; i++) {
    for (j = 0; j < 16; j += 8) {
        register uint32_t x;
        // Consecutive 8-byte load using array indexing instead of pointer dereference
        const uint8_t *p = pix;
        x = ((uint32_t)p[0]) | ((uint32_t)p[1] << 8) | ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
        s += sq[x & 255];
        s += sq[(x >> 8) & 255];
        s += sq[(x >> 16) & 255];
        s += sq[(x >> 24) & 255];
        x = ((uint32_t)p[4]) | ((uint32_t)p[5] << 8) | ((uint32_t)p[6] << 16) | ((uint32_t)p[7] << 24);
        s += sq[x & 255];
        s += sq[(x >> 8) & 255];
        s += sq[(x >> 16) & 255];
        s += sq[(x >> 24) & 255];
        pix += 8;
    }
    pix += line_size - 16;
}
}
