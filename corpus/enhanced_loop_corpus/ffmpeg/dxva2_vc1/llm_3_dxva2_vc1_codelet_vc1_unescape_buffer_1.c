#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int size;
extern uint8_t *dst;
extern int dsize;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via arithmetic)
    int indices[2] = {0, 1}; // Simulate small lookup pattern
    for (dsize = 0; dsize < size; dsize++) {
        int idx = (dsize % 2 == 0) ? indices[0] : indices[1];
        *dst++ = src[(dsize & ~1) + idx]; // Access in pairs: 0,1, then 2,3, etc.
    }
}
