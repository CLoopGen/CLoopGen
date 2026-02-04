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
    for (i = 0; i < w; i += 2) {
        if (i + 1 < w) {
            b += src[4 * i + 0] + src[4 * (i + 1) + 0];
            g += src[4 * i + 1] + src[4 * (i + 1) + 1];
            r += src[4 * i + 2] + src[4 * (i + 1) + 2];
            a += src[4 * i + 3] + src[4 * (i + 1) + 3];

            dst[4 * i + 0] = b;
            dst[4 * i + 1] = g;
            dst[4 * i + 2] = r;
            dst[4 * i + 3] = a;

            dst[4 * (i + 1) + 0] = b;
            dst[4 * (i + 1) + 1] = g;
            dst[4 * (i + 1) + 2] = r;
            dst[4 * (i + 1) + 3] = a;
        } else {
            b += src[4 * i + 0];
            g += src[4 * i + 1];
            r += src[4 * i + 2];
            a += src[4 * i + 3];
            dst[4 * i + 0] = b;
            dst[4 * i + 1] = g;
            dst[4 * i + 2] = r;
            dst[4 * i + 3] = a;
        }
    }
}
