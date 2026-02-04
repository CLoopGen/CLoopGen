#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern int size;
extern int i;
extern int r;
extern int g;
extern int b;
extern int a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 1;
    for (; i <= size - 12; i += 12) {
        dst[i + 0]  = r = (r + src[i + 0]) + 1;
        dst[i + 1]  = g = (g + src[i + 1]) + 1;
        dst[i + 2]  = b = (b + src[i + 2]) + 1;
        dst[i + 3]  = a = (a + src[i + 3]) + 1;

        dst[i + 4]  = r = (r + src[i + 4]) + 1;
        dst[i + 5]  = g = (g + src[i + 5]) + 1;
        dst[i + 6]  = b = (b + src[i + 6]) + 1;
        dst[i + 7]  = a = (a + src[i + 7]) + 1;

        dst[i + 8]  = r = (r + src[i + 8]) + 1;
        dst[i + 9]  = g = (g + src[i + 9]) + 1;
        dst[i + 10] = b = (b + src[i + 10]) + 1;
        dst[i + 11] = a = (a + src[i + 11]) + 1;

        step *= 2;
    }
}
