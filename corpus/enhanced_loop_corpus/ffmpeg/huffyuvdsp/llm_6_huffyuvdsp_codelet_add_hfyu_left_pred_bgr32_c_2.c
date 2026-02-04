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
    uint8_t temp_b = b;
    uint8_t temp_g = g;
    uint8_t temp_r = r;
    uint8_t temp_a = a;
    for (i = 0; i < w; i++) {
        temp_b += src[4 * i + 0];
        temp_g += src[4 * i + 1];
        temp_r += src[4 * i + 2];
        temp_a += src[4 * i + 3];
        dst[4 * i + 0] = temp_b;
        dst[4 * i + 1] = temp_g;
        dst[4 * i + 2] = temp_r;
        dst[4 * i + 3] = temp_a;
    }
    b = temp_b;
    g = temp_g;
    r = temp_r;
    a = temp_a;
}
