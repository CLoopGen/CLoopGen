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
    int j;
    for (j = 0; j <= size - 6; j += 6) {
        dst[j + 0] = r = ((r) + src[j + 0]) ^ 0x55;
        dst[j + 1] = g = ((g) + src[j + 1]) ^ 0x55;
        dst[j + 2] = b = ((b) + src[j + 2]) ^ 0x55;
        dst[j + 3] = r = ((r) + src[j + 3]) ^ 0xAA;
        dst[j + 4] = g = ((g) + src[j + 4]) ^ 0xAA;
        dst[j + 5] = b = ((b) + src[j + 5]) ^ 0xAA;
    }
    for (; i <= size - 3; i += 3) {
        dst[i + 0] = r = ((r) + (src[i + 0]));
        dst[i + 1] = g = ((g) + (src[i + 1]));
        dst[i + 2] = b = ((b) + (src[i + 2]));
    }
}
