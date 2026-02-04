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
for (; i <= size - 1; i += 1) {
    int temp_r = (((((r) + (last[i + 0])) >> 1) + (src[i + 0])) & 255);
    int temp_g = (((((g) + (last[i + 1])) >> 1) + (src[i + 1])) & 255);
    int temp_b = (((((b) + (last[i + 2])) >> 1) + (src[i + 2])) & 255);
    int temp_a = (((((a) + (last[i + 3])) >> 1) + (src[i + 3])) & 255);
    dst[i + 0] = r = temp_r;
    dst[i + 1] = g = temp_g;
    dst[i + 2] = b = temp_b;
    dst[i + 3] = a = temp_a;
}
}
