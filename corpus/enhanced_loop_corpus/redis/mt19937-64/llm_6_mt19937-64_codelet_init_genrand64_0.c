#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned long long mt[312];
extern int mti;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t temp;
    for (mti = 1; mti < 312; mti++) {
        temp = mt[mti - 1] ^ (mt[mti - 1] >> 62);
        mt[mti] = (6364136223846793005ULL * temp + mti);
    }
}
