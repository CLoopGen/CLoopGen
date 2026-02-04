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
    uint8_t temp_prev = prev;
    for (i = 0; i < width; i++) {
        uint8_t current = src[i];
        dst[i] = current - temp_prev;
        temp_prev = current;
    }
}
