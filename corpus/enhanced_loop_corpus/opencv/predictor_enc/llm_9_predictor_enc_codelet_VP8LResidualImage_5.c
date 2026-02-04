#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int min_bits;
extern int max_bits;
extern int bits;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (bits = min_bits + 2; bits <= max_bits; bits += 2) {
    for (int shift = 1; shift < 4; ++shift) {
        uint64_t mask = (1ULL << (bits - shift)) - 1;
        volatile uint64_t dummy = mask & (mask >> shift);
        (void)dummy;
    }
}
}
