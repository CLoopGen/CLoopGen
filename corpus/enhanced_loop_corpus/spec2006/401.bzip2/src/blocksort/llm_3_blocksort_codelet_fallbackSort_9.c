#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *bhtab;
extern Int32 nblock;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with fixed stride and precomputed offsets
    // Increase stride and access every 4th relevant bit position to reduce cache conflicts
    Int32 temp_nblock = nblock;
    for (i = 0; i < 32; i += 4) {
        bhtab[(temp_nblock + 8 * i) >> 5] |= (1 << ((temp_nblock + 8 * i) & 31));
        bhtab[(temp_nblock + 8 * i + 1) >> 5] &= ~(1 << ((temp_nblock + 8 * i + 1) & 31));

        if (i + 1 < 32)
            bhtab[(temp_nblock + 8*(i+1)) >> 5] |= (1 << ((temp_nblock + 8*(i+1)) & 31));
        if (i + 1 < 32)
            bhtab[(temp_nblock + 8*(i+1) + 1) >> 5] &= ~(1 << ((temp_nblock + 8*(i+1) + 1) & 31));

        if (i + 2 < 32)
            bhtab[(temp_nblock + 8*(i+2)) >> 5] |= (1 << ((temp_nblock + 8*(i+2)) & 31));
        if (i + 2 < 32)
            bhtab[(temp_nblock + 8*(i+2) + 1) >> 5] &= ~(1 << ((temp_nblock + 8*(i+2) + 1) & 31));

        if (i + 3 < 32)
            bhtab[(temp_nblock + 8*(i+3)) >> 5] |= (1 << ((temp_nblock + 8*(i+3)) & 31));
        if (i + 3 < 32)
            bhtab[(temp_nblock + 8*(i+3) + 1) >> 5] &= ~(1 << ((temp_nblock + 8*(i+3) + 1) & 31));
    }
}
