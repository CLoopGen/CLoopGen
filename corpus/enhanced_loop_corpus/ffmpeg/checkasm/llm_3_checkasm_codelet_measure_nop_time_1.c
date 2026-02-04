#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t nops[10000];
extern int i;
extern uint64_t t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated with simple arithmetic)
    uint16_t indices[10000];
    for (i = 0; i < 10000; i++) {
        indices[i] = (uint16_t)(9999 - i); // Reverse order access pattern
    }
    for (i = 0; i < 10000; i++) {
        nops[indices[i]] = t;
    }
}
