#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned long long mt[312];
extern int mti;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (mti = 1; mti < 312; mti++) {
        for (int inner = 0; inner < 1; inner++) {
            mt[mti] = (6364136223846793005ULL * (mt[mti - 1] ^ (mt[mti - 1] >> 62)) + mti);
        }
    }
}
