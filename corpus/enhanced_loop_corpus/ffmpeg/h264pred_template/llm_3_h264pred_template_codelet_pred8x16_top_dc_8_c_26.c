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
    // Variant 2: Strided memory access with fixed step through array
    ptrdiff_t offset = -stride;
    for (i = 0; i < 8; i += 2) {
        dc0 += src[offset + i];
        dc1 += src[offset + i + 1];
    }
}
