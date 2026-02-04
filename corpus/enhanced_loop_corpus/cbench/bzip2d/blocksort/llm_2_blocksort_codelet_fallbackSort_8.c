#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *bhtab;
extern Int32 ftab[257];
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access pattern
    // Instead of accessing bhtab with ftab[i] derived indices in natural order,
    // we traverse i in a strided manner (stride of 2) to create non-consecutive accesses.
    for (i = 0; i < 256; i += 2)
        bhtab[(ftab[i]) >> 5] |= (1 << ((ftab[i]) & 31));
    for (i = 1; i < 256; i += 2)
        bhtab[(ftab[i]) >> 5] |= (1 << ((ftab[i]) & 31));
}
