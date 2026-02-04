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
    for (; i <= size - 6; i += 6) {
        dst[i + 0] = r = (((r + last[i + 0]) >> 1) + src[i + 0]) & 255;
        dst[i + 1] = g = (((g + last[i + 1]) >> 1) + src[i + 1]) & 255;
        dst[i + 2] = b = (((b + last[i + 2]) >> 1) + src[i + 2]) & 255;
        dst[i + 3] = r = (((r + last[i + 3]) >> 1) + src[i + 3]) & 255;
        dst[i + 4] = g = (((g + last[i + 4]) >> 1) + src[i + 4]) & 255;
        dst[i + 5] = b = (((b + last[i + 5]) >> 1) + src[i + 5]) & 255;
    }
}
