#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int mti;
extern uint32_t *mt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (step of 2), with boundary adjustment
    for (mti = 1; mti < 624; mti += 2) {
        if (mti - 2 >= 0) {
            mt[mti] = (1812433253UL * (mt[mti - 2] ^ (mt[mti - 2] >> 30)) + mti);
            mt[mti] &= 4294967295UL;
        }
        if (mti + 1 < 624) {
            mt[mti + 1] = (1812433253UL * (mt[mti - 1] ^ (mt[mti - 1] >> 30)) + (mti + 1));
            mt[mti + 1] &= 4294967295UL;
        }
    }
}
