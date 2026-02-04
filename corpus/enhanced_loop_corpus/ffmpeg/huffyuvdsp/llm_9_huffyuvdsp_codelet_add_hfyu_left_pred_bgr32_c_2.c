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
    for (i = 0; i < w && i < 64; i++) {
        uint8_t temp_r = src[4 * i + 2];
        uint8_t temp_g = src[4 * i + 1];
        uint8_t temp_b = src[4 * i + 0];
        uint8_t temp_a = src[4 * i + 3];

        b += temp_b;
        g += temp_g;
        r += temp_r;
        a += temp_a;

        dst[4 * i + 0] = b ^ temp_g;
        dst[4 * i + 1] = g ^ temp_b;
        dst[4 * i + 2] = r ^ temp_a;
        dst[4 * i + 3] = a ^ temp_r;
    }
}
