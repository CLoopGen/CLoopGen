#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned long long mt[312];
extern int i;
extern unsigned long long x;
extern unsigned long long mag01[2];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with unrolled operations and increased trip count via inner loop
    int j;
    for (; i < 312 - 4; i += 4) {
        for (j = 0; j < 4; j++) {
            if (i + j >= 311) break;
            x = (mt[i + j] & 18446744071562067968ULL) | (mt[i + j + 1] & 2147483647ULL);
            mt[i + j] = mt[i + j + (156 - 312)] ^ (x >> 1) ^ mag01[(int)(x & 1ULL)];
            // Additional arithmetic to increase complexity
            mt[i + j] ^= (mt[i + j] << 13);
            mt[i + j] ^= (mt[i + j] >> 7);
        }
    }
}
