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
for (; i <= size - 3; i += 3) {
    dst[i + 0] = r = (((((r) + (last[i + 0])) >> 1) + (src[i + 0])) & 255);
    if (3 > 1) {
        dst[i + 1] = g = (((((g) + (last[i + 1])) >> 1) + (src[i + 1])) & 255);
        if (3 > 2) {
            dst[i + 2] = b = (((((b) + (last[i + 2])) >> 1) + (src[i + 2])) & 255);
        }
    }
}
}
