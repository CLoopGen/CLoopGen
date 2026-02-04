#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned long long mt[312];
extern unsigned long long i;
extern unsigned long long k;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    unsigned long long temp;
    for (k = 312 - 1; k; k--) {
        temp = mt[i - 1] ^ (mt[i - 1] >> 62);
        mt[i] = (mt[i] ^ (temp * 2862933555777941757ULL)) - i;
        i++;
        if (i >= 312) {
            mt[0] = mt[312 - 1];
            i = 1;
        }
    }
}
