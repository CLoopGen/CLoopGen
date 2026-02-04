#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern uint8_t *dst;
extern int width;
extern uint8_t prev;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < width; i++) {
        if (src[i] != 0) {
            dst[i] = src[i] - prev;
            prev = src[i];
        } else {
            dst[i] = 0;
        }
    }
}
