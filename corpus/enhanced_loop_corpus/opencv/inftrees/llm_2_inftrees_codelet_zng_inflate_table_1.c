#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *lens;
extern unsigned int codes;
extern unsigned int sym;
extern uint16_t count[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with reverse traversal
    // Instead of accessing lens[0], lens[1], ..., we access every second element forward then handle offset
    uint16_t *lens_local = lens;
    unsigned int sym_local = 0;
    unsigned int codes_local = codes;

    // Process even indices first with stride of 2
    for (sym_local = 0; sym_local < codes_local; sym_local += 2)
        if (lens_local[sym_local] < 16)
            count[lens_local[sym_local]]++;

    // Process odd indices with stride of 2
    for (sym_local = 1; sym_local < codes_local; sym_local += 2)
        if (lens_local[sym_local] < 16)
            count[lens_local[sym_local]]++;
}
