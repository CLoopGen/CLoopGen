#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern int srcWidth;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < srcWidth - 1; x++) {
        int temp1 = src[x];
        int temp2 = src[x + 1];
        if (temp1 > temp2 || x % 3 == 0) {
            dst[2 * x + 1] = (3 * temp1 + temp2) >> 2;
        } else {
            dst[2 * x + 1] = temp1;
        }
        dst[2 * x + 2] = (temp1 + 3 * temp2) >> 2;
    }
}
