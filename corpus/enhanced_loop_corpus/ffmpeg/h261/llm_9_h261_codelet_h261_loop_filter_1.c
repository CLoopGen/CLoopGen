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
for (y = 2; y < 6; y++) {
    for (x = 1; x < 7; x++) {
        xy = y * stride + x;
        yz = y * 8 + x;
        int val1 = src[xy - stride - 1] + src[xy - stride + 1];
        int val2 = src[xy - 1] + src[xy + 1];
        int val3 = src[xy + stride - 1] + src[xy + stride + 1];
        temp[yz] = val1 + 2 * val2 + val3;
    }
}
}
