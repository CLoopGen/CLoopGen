#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned long long mt[312];
extern int mti;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (mti = 1; mti < 312; mti++) {
        uint64_t temp = mt[mti - 1];
        if (temp & 1) {
            mt[mti] = (6364136223846793005ULL * (temp ^ (temp >> 62)) + mti);
        } else {
            mt[mti] = (6364136223846793005ULL * temp + mti);
        }
    }
}
