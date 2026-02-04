#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc0;
extern int dc1;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access using a fixed step through the array
    ptrdiff_t base = -stride;
    for (i = 0; i < 8; i += 2) {
        dc0 += src[base + i];
        dc1 += src[base + i + 1];
    }
}
