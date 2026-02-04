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
    for (x = 0; x < w - 15; x += 16) {
        dst[x + 0]  = src[2 * x + 0];
        dst[x + 1]  = src[2 * x + 2];
        dst[x + 2]  = src[2 * x + 4];
        dst[x + 3]  = src[2 * x + 6];
        dst[x + 4]  = src[2 * x + 8];
        dst[x + 5]  = src[2 * x + 10];
        dst[x + 6]  = src[2 * x + 12];
        dst[x + 7]  = src[2 * x + 14];
        dst[x + 8]  = src[2 * x + 16];
        dst[x + 9]  = src[2 * x + 18];
        dst[x + 10] = src[2 * x + 20];
        dst[x + 11] = src[2 * x + 22];
        dst[x + 12] = src[2 * x + 24];
        dst[x + 13] = src[2 * x + 26];
        dst[x + 14] = src[2 * x + 28];
        dst[x + 15] = src[2 * x + 30];
    }
}
