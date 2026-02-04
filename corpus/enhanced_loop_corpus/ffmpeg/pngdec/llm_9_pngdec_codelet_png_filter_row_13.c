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
int j;
for (j = 0; j < size && i <= size - 1; j++, i += 1) {
    dst[i + 0] = r = ((r + last[i + 0] + src[i + 0]) >> 1) & 255;
    if (j % 2 == 0) {
        dst[i + 1] = g = ((g + last[i + 1] + src[i + 1]) >> 1) & 255;
    }
    if (j % 3 == 0) {
        dst[i + 2] = b = ((b + last[i + 2] + src[i + 2]) >> 1) & 255;
    }
}
}
