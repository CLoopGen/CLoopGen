#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern  uint8_t *f1;
extern  uint8_t *f2;
extern int w;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int x = 0; x < w; x++) {
        int val1 = src[x] - f1[x];
        int val2 = src[x] - f2[x];
        val1 = (val1 ^ (val1 >> 31)) - (val1 >> 31); // Fast abs for signed 8-bit
        val2 = (val2 ^ (val2 >> 31)) - (val2 >> 31); // Branchless absolute value
        dst[x] = (val2 > val1) ? f2[x] : f1[x];
    }
}
