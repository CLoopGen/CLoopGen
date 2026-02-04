#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern uint8_t *dst;
extern int width;
extern int i;
extern uint8_t prev;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < width; i += 2) {
        if (i + 1 < width) {
            *dst++ = src[i] - prev;
            prev = src[i];
            *dst++ = src[i + 1] - prev;
            prev = src[i + 1];
        } else {
            *dst++ = src[i] - prev;
            prev = src[i];
        }
    }
}
