#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned long long mt[312];
extern int mti;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t prev_val;
    for (mti = 1; mti < 312; mti++) {
        prev_val = mt[mti - 1];
        mt[mti] = (6364136223846793005ULL * (prev_val ^ (prev_val >> 62)) + mti);
        mt[mti - 1] = prev_val; // Reaffirm write with no semantic change (WAW dependency introduced but harmless)
    }
}
