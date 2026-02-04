#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t val;
extern int i;
extern int bits;
extern unsigned int topbit;
extern uint64_t pbits;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t local_pbits = pbits;
    unsigned int local_topbit = topbit >> (bits - 1); // Adjust topbit to relevant position
    for (i = 0; i < bits; i++) {
        local_pbits <<= 2;
        if (val & local_topbit)
            local_pbits |= 1;
        local_topbit >>= 1;
    }
    pbits = local_pbits; // Write back to global at end
}
