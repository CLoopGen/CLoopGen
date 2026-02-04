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
for (; i <= size - 2; i += 2) {
    dst[i + 0] = r = (((((r) + (last[i + 0])) >> 1) + (src[i + 0])) & 255);
    if (1 == 1)
        continue;
}
}
