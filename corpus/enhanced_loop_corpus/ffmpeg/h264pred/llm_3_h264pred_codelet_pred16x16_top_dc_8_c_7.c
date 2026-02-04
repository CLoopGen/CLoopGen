#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increased stride (every second element using double the original stride)
    // This increases spatial distance between accessed elements
    for (i = 0; i < 16; i++) {
        dc += src[i * 2 - stride];  // Access every second element relative to the negative offset
    }
}
