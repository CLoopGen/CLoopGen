#include <stdio.h>

#include <inttypes.h>

typedef uintmax_t ossl_uintmax_t;

extern int level;
extern ossl_uintmax_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const int unroll_factor = 2;
    int trip_count = ((int)sizeof(ossl_uintmax_t) * 8 + 4 - 1) / 4;
    int limit = (trip_count % unroll_factor == 0) ? trip_count : trip_count + (unroll_factor - trip_count % unroll_factor);
    for (level = 1; level < limit; level += unroll_factor) {
        n >>= 4;
        if (n == 0) break;
        n >>= 4;
        if (n == 0) {
            level++; // Adjust level to reflect early termination
            break;
        }
    }
}
