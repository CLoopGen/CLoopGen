#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int stride;
extern int x;
extern int y;
extern int xy;
extern int yz;
extern int temp[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 4; y++) {
    src[y * stride] = (temp[y * 8] + 1) >> 1;
    src[y * stride + 3] = (temp[y * 8 + 3] + 1) >> 1;
    for (x = 1; x < 3; x++) {
        xy = y * stride + x;
        yz = y * 8 + x;
        src[xy] = (temp[yz] + 4) >> 3;
    }
}
}
