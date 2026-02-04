#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned long long mt[312];
extern int mti;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (step of 2), unrolling the loop to process two elements per iteration
    // We handle even and odd indices separately to maintain correctness across iterations
    for (mti = 1; mti < 312; mti += 2) {
        if (mti - 1 >= 0) {
            mt[mti] = (6364136223846793005ULL * (mt[mti - 1] ^ (mt[mti - 1] >> 62)) + mti);
        }
        if (mti + 1 < 312) {
            mt[mti + 1] = (6364136223846793005ULL * (mt[mti] ^ (mt[mti] >> 62)) + (mti + 1));
        }
    }
}
