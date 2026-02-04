#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *lens;
extern unsigned int codes;
extern uint16_t *work;
extern unsigned int sym;
extern uint16_t offs[16];

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access pattern
    // Instead of iterating sequentially, process every second element in two passes
    for (sym = 0; sym < codes; sym += 2)
        if (lens[sym] != 0)
            work[offs[lens[sym]]++] = (uint16_t)sym;

    for (sym = 1; sym < codes; sym += 2)
        if (lens[sym] != 0)
            work[offs[lens[sym]]++] = (uint16_t)sym;
}
