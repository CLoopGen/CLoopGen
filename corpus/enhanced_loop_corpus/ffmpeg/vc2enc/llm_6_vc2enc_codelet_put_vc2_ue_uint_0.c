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
    uint32_t temp_val = val;
    unsigned int temp_topbit = topbit;
    for (i = 0; i < bits; i++) {
        if (temp_val & temp_topbit)
            pbits |= 1ULL << (2 * i);
        temp_topbit >>= 1;
        pbits <<= 2;
    }
}
