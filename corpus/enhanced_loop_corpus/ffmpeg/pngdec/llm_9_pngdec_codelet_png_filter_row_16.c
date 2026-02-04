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
        int temp_r = ((r + last[i + 0]) >> 1) + src[i + 0];
        int temp_g = ((g + last[i + 0]) >> 1) + src[i + 0];
        dst[i + 0] = r = (temp_r + temp_g) & 255;
        if (i + 1 >= size) break;
        int temp_b = ((b + last[i + 1]) >> 1) + src[i + 1];
        int temp_a = ((a + last[i + 1]) >> 1) + src[i + 1];
        dst[i + 1] = b = (temp_b + temp_a) & 255;
        r = (r + b) & 255;
        g = (g + a) & 255;
    }
}
