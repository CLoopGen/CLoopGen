#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned long long mt[312];
extern int mti;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (mti = 2; mti < 312; mti += 2) {
        uint64_t val_prev1 = mt[mti - 1];
        uint64_t val_prev2 = mt[mti - 2];
        uint64_t combined = (val_prev1 ^ (val_prev1 >> 62)) + (val_prev2 ^ (val_prev2 >> 62));
        mt[mti] = 6364136223846793005ULL * combined + mti;
        if (mti + 1 < 312) {
            mt[mti + 1] = 6364136223846793005ULL * (mt[mti] ^ (mt[mti] >> 62)) + (mti + 1);
        }
    }
}
