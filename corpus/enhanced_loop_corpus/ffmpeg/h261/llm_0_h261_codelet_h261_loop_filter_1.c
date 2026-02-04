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
for (y = 1; y < 7; y++) {
    xy = y * stride + 0;
    yz = y * 8 + 0;
    temp[yz] = src[xy - stride] + 2 * src[xy] + src[xy + stride];
    xy++;
    yz++;
    temp[yz] = src[xy - stride] + 2 * src[xy] + src[xy + stride];
    xy++;
    yz++;
    temp[yz] = src[xy - stride] + 2 * src[xy] + src[xy + stride];
    xy++;
    yz++;
    temp[yz] = src[xy - stride] + 2 * src[xy] + src[xy + stride];
    xy++;
    yz++;
    temp[yz] = src[xy - stride] + 2 * src[xy] + src[xy + stride];
    xy++;
    yz++;
    temp[yz] = src[xy - stride] + 2 * src[xy] + src[xy + stride];
    xy++;
    yz++;
    temp[yz] = src[xy - stride] + 2 * src[xy] + src[xy + stride];
}
}
