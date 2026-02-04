#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp1, temp2, temp3, temp4;
    for (x -= 7; x >= 0; x -= 8) {
        temp1 = src[(x >> 1) + 3];
        temp2 = src[(x >> 1) + 2];
        temp3 = src[(x >> 1) + 1];
        temp4 = src[(x >> 1) + 0];

        dst[x + 6] = temp1;
        dst[x + 7] = temp1;
        dst[x + 4] = temp2;
        dst[x + 5] = temp2;
        dst[x + 2] = temp3;
        dst[x + 3] = temp3;
        dst[x + 0] = temp4;
        dst[x + 1] = temp4;
    }
}
