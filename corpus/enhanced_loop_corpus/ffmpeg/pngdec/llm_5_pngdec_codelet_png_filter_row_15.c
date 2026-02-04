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
    int step = 0;
    dst[i + step] = r = (((((r) + (last[i + step])) >> 1) + (src[i + step])) & 255);
    step++;
    if (step < 3) {
        dst[i + step] = g = (((((g) + (last[i + step])) >> 1) + (src[i + step])) & 255);
        step++;
        if (step < 3) {
            dst[i + step] = b = (((((b) + (last[i + step])) >> 1) + (src[i + step])) & 255);
        }
    }
}
}
