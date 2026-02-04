#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *ptr;
extern uint8_t planes[4][1024];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 1024; i += 8) {
    for (int j = 0; j < 8 && (i + j) < 1024; j++) {
        int idx = i + j;
        int r = ptr[j*4+0];
        int g = ptr[j*4+1];
        int b = ptr[j*4+2];
        int a = ptr[j*4+3];
        
        int y = ((25 * r + 129 * g + 66 * b + 128) >> 8) + 16;
        int u = ((-38 * r + 112 * g - 74 * b + 128) >> 8) + 128;
        int v = ((-18 * r + 112 * g - 94 * b + 128) >> 8) + 128;
        
        y = y < 0 ? 0 : y > 255 ? 255 : y;
        u = u < 0 ? 0 : u > 255 ? 255 : u;
        v = v < 0 ? 0 : v > 255 ? 255 : v;
        
        planes[0][idx] = y;
        planes[1][idx] = u;
        planes[2][idx] = v;
        planes[3][idx] = a;
    }
    ptr += 32;
}
}
