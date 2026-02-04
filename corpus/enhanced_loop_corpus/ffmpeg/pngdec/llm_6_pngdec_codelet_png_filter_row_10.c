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
        int temp_r = src[i + 0] + r;
        dst[i + 0] = temp_r;
        r = temp_r;

        int temp_g = src[i + 1] + g;
        dst[i + 1] = temp_g;
        g = temp_g;

        int temp_b = src[i + 2] + b;
        dst[i + 2] = temp_b;
        b = temp_b;
    }
}
