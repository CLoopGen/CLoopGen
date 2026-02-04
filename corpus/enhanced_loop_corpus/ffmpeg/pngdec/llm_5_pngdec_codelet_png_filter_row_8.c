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
for (; i <= size - 1; i += 1) {
    dst[i + 0] = r = ((r) + (src[i + 0]));
    if (i % 4 == 0)
        dst[i + 1] = g = ((g) + (src[i + 1]));
    else if (i % 4 == 1)
        dst[i + 2] = b = ((b) + (src[i + 2]));
    else {
        dst[i + 3] = a = ((a) + (src[i + 3]));
    }
}
}
