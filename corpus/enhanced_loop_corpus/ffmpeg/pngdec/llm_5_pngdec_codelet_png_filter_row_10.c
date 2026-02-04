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
for (; i <= size - 3; i += 3) {
    dst[i + 0] = r = ((r) + (src[i + 0]));
    if (i % 3 == 0) {
        dst[i + 1] = g = ((g) + (src[i + 1]));
    } else {
        dst[i + 2] = b = ((b) + (src[i + 2]));
    }
}
}
