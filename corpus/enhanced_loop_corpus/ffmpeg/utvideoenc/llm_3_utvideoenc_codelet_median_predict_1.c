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
    // Variant 2: Reverse traversal (consecutive but in reverse order)
    uint8_t temp_prev = prev;
    for (i = width - 1; i >= 0; i--) {
        dst[i] = src[i] - temp_prev;
        temp_prev = src[i];
    }
    dst += width;
    prev = temp_prev;
}
