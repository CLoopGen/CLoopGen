#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const uint8_t ff_reverse[256];
extern  uint8_t *src;
extern int size;
extern int i;
extern uint8_t *src2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive access pattern
    // Iterates from the end of the array to the beginning
    for (i = size - 1; i >= 0; i--) {
        src2[i] = ff_reverse[src[i]];
    }
}
