#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *bhtab;
extern Int32 nblock;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 32; i += 2) {
        Int32 base = nblock + 2 * i;

        // First iteration step: current i
        bhtab[(base) >> 5] |= (1 << (base & 31));
        bhtab[(base + 1) >> 5] &= ~(1 << ((base + 1) & 31));

        // Second iteration step: i+1, unrolled to create WAW and RAW dependencies
        if (i + 1 < 32) {
            Int32 next_base = nblock + 2 * (i + 1);
            bhtab[(next_base) >> 5] |= (1 << (next_base & 31));
            bhtab[(next_base + 1) >> 5] &= ~(1 << ((next_base + 1) & 31));
        }
    }
}
