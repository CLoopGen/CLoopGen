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
    int j = i;
    for (; j <= size - 3; j += 3) {
        int temp_r = (((r + last[j + 0]) >> 1) + src[j + 0]) & 255;
        int temp_g = (((g + last[j + 1]) >> 1) + src[j + 1]) & 255;
        int temp_b = (((b + last[j + 2]) >> 1) + src[j + 2]) & 255;
        dst[j + 0] = r = temp_r;
        dst[j + 1] = g = temp_g;
        dst[j + 2] = b = temp_b;
    }
    i = j;
}
