#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse-order consecutive memory access with offset
    // Access elements from the end of a 16-element window ending at index 0 (i.e., indices -15 to 0)
    for (i = 0; i < 16; i++) {
        dc += src[-15 + i];
    }
}
