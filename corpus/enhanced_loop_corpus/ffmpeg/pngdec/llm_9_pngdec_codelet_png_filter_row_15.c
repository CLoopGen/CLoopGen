#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern uint8_t *last;
extern int size;
extern int i;
extern int r;
extern int g;
extern int b;
extern int a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; i <= size - 12; i += 12) {
        int j;
        for (j = 0; j < 12; j += 3) {
            dst[i + j + 0] = r = (((r + last[i + j + 0]) >> 1) + src[i + j + 0]) & 255;
            dst[i + j + 1] = g = (((g + last[i + j + 1]) >> 1) + src[i + j + 1]) & 255;
            dst[i + j + 2] = b = (((b + last[i + j + 2]) >> 1) + src[i + j + 2]) & 255;
        }
    }
}
