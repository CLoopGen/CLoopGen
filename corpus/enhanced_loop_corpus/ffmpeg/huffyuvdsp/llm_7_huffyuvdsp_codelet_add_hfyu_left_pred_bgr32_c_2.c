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
        uint8_t new_b = b + src[4 * i + 0];
        uint8_t new_g = g + src[4 * i + 1];
        uint8_t new_r = r + src[4 * i + 2];
        uint8_t new_a = a + src[4 * i + 3];
        dst[4 * i + 0] = new_b;
        dst[4 * i + 1] = new_g;
        dst[4 * i + 2] = new_r;
        dst[4 * i + 3] = new_a;
        b = new_b;
        g = new_g;
        r = new_r;
        a = new_a;
    }
}
