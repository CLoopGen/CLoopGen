#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned long long mt[312];
extern unsigned long long i;
extern unsigned long long k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 156; k > 0; k--) { // Reduced trip count by approximately half
        mt[i] = (mt[i] ^ ((mt[i - 1] ^ (mt[i - 1] >> 62)) * 2862933555777941757ULL)) - i;
        i += 2; // Advance index faster to maintain progress across array
        if (i >= 312) {
            mt[0] = mt[312 - 1];
            i = (i == 312) ? 0 : 1; // Adjust i to stay within bounds
        }
        if (i == 0) i = 1; // Ensure i never remains 0 to prevent invalid access in next iteration
    }
}
