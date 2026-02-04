#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *bhtab;
extern Int32 ftab[257];
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern
    // Instead of accessing ftab sequentially, use a stride of 2 (unrolled-like pattern)
    // This changes the access order and may affect cache behavior
    for (i = 0; i < 256; i += 2) {
        bhtab[(ftab[i]) >> 5] |= (1 << ((ftab[i]) & 31));
        if (i + 1 < 256) {
            bhtab[(ftab[i + 1]) >> 5] |= (1 << ((ftab[i + 1]) & 31));
        }
    }
}
