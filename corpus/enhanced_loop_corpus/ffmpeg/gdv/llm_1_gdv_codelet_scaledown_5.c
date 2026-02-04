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
    for (int offset = 0; offset < 16; offset += 8) {
        if (x + offset < w - 7) {
            dst[x + offset + 0] = src[2 * (x + offset) + 0];
            dst[x + offset + 1] = src[2 * (x + offset) + 2];
            dst[x + offset + 2] = src[2 * (x + offset) + 4];
            dst[x + offset + 3] = src[2 * (x + offset) + 6];
            dst[x + offset + 4] = src[2 * (x + offset) + 8];
            dst[x + offset + 5] = src[2 * (x + offset) + 10];
            dst[x + offset + 6] = src[2 * (x + offset) + 12];
            dst[x + offset + 7] = src[2 * (x + offset) + 14];
        }
    }
}
}
