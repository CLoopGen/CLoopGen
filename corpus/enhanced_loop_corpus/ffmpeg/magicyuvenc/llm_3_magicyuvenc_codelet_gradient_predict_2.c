#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern uint8_t *dst;
extern int width;
extern int left;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive access from end to start
    for (i = width - 1; i >= 0; i--) {
        dst[i] = src[i] - left;
        left = src[i];
    }
}
