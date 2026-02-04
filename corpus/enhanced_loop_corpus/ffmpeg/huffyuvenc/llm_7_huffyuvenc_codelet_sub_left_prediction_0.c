#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int left;
extern int i;
extern int min_width;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t prev_left = left;
    for (i = 0; i < min_width; i++) {
        const int current_src = src[i];
        dst[i] = current_src - prev_left;
        prev_left = current_src;
    }
}
