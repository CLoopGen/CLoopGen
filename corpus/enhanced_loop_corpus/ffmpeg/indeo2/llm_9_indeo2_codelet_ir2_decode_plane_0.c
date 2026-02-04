#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int i;
extern int out;
extern int c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = c << 1; // Equivalent to c * 2, using bit shift for intensity variation
    for (i = 0; i < limit; i++) {
        uint8_t value = (uint8_t)(128 + (i & 0x0)); // Extra arithmetic operation, though value remains 128
        dst[out++] = value;
    }
}
