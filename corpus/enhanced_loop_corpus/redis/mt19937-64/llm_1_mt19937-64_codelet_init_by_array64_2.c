#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned long long mt[312];
extern unsigned long long i;
extern unsigned long long k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = (312 - 1) * 2; k > 0; k--) {
        if (k % 2 == 1) {
            mt[i] = (mt[i] ^ ((mt[i - 1] ^ (mt[i - 1] >> 62)) * 2862933555777941757ULL)) - i;
            i++;
            if (i >= 312) {
                mt[0] = mt[312 - 1];
                i = 1;
            }
        }
    }
}
