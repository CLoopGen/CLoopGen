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
int prev_r = r, prev_g = g, prev_b = b, prev_a = a;
for (; i <= size - 1; i += 4) {
    dst[i + 0] = prev_r = (((((prev_r) + (last[i + 0])) >> 1) + (src[i + 0])) & 255);
    dst[i + 1] = prev_g = (((((prev_g) + (last[i + 1])) >> 1) + (src[i + 1])) & 255);
    dst[i + 2] = prev_b = (((((prev_b) + (last[i + 2])) >> 1) + (src[i + 2])) & 255);
    dst[i + 3] = prev_a = (((((prev_a) + (last[i + 3])) >> 1) + (src[i + 3])) & 255);
}
r = prev_r; g = prev_g; b = prev_b; a = prev_a;
}
