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
if (width > 0) {
    for (i = 0; i < width; i++) {
        uint8_t temp = src[i];
        for (int k = 0; k < 1; k++) {
            *dst++ = temp - prev;
            prev = temp;
        }
    }
}
}
