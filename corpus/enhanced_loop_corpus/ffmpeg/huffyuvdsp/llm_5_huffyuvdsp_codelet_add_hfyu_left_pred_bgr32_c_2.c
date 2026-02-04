#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern intptr_t w;
extern int i;
extern uint8_t r;
extern uint8_t g;
extern uint8_t b;
extern uint8_t a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < w; i++) {
        uint8_t temp_b = src[4 * i + 0];
        uint8_t temp_g = src[4 * i + 1];
        uint8_t temp_r = src[4 * i + 2];
        uint8_t temp_a = src[4 * i + 3];

        if (temp_b > 128) b += temp_b;
        if (temp_g > 128) g += temp_g;
        if (temp_r > 128) r += temp_r;
        if (temp_a > 128) a += temp_a;

        dst[4 * i + 0] = b;
        dst[4 * i + 1] = g;
        dst[4 * i + 2] = r;
        dst[4 * i + 3] = a;
    }
}
