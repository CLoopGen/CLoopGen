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
    for (x = 0; x < w - 7; x += 8) {
        uint8_t temp0 = src[2 * x + 0];
        uint8_t temp1 = src[2 * x + 2];
        uint8_t temp2 = src[2 * x + 4];
        uint8_t temp3 = src[2 * x + 6];
        uint8_t temp4 = src[2 * x + 8];
        uint8_t temp5 = src[2 * x + 10];
        uint8_t temp6 = src[2 * x + 12];
        uint8_t temp7 = src[2 * x + 14];

        dst[x + 0] = temp0;
        dst[x + 1] = temp1;
        dst[x + 2] = temp2;
        dst[x + 3] = temp3;
        dst[x + 4] = temp4;
        dst[x + 5] = temp5;
        dst[x + 6] = temp6;
        dst[x + 7] = temp7;
    }
}
