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
    for (y = 2; y < 8; y++) {
        for (x = 0; x < 8; x++) {
            xy = y * stride + x;
            yz = (y - 1) * 8 + x;
            temp[yz] = src[xy - 2 * stride] + 2 * src[xy - stride] + src[xy];
        }
    }
}
