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
for (; i <= size - 4; i += 4) {
    int temp_r = r + src[i + 0];
    int temp_g = g + src[i + 1];
    int temp_b = b + src[i + 2];
    int temp_a = a + src[i + 3];

    dst[i + 0] = temp_r;
    dst[i + 1] = temp_g;
    dst[i + 2] = temp_b;
    dst[i + 3] = temp_a;

    r = temp_r;
    g = temp_g;
    b = temp_b;
    a = temp_a;
}
}
