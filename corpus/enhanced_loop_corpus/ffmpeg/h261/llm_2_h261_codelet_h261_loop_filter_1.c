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
    int base_src = y * stride;
    int base_temp = y * 8;
    for (x = 0; x < 8; x++) {
        xy = base_src + x;
        temp[base_temp + x] = src[xy - stride] + 2 * src[xy] + src[xy + stride];
    }
}
}
