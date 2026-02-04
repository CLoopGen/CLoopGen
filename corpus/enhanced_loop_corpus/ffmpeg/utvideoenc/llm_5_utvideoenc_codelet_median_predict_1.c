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
    for (i = 0; i < width; i++) {
        if (src[i] != prev) {
            *dst++ = src[i] - prev;
        } else {
            *dst++ = 0;
        }
        prev = src[i];
    }
}
