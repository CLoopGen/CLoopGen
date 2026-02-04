#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned long long mt[312];
extern unsigned long long i;
extern unsigned long long k;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    unsigned long long prev_index = (i == 0) ? 311 : i - 1;
    for (k = 312 - 1; k; k--) {
        mt[i] = (mt[i] ^ ((mt[prev_index] ^ (mt[prev_index] >> 62)) * 2862933555777941757ULL)) - i;
        i++;
        prev_index = i - 1;
        if (i >= 312) {
            mt[0] = mt[312 - 1];
            i = 1;
            prev_index = 311;
        }
    }
}
