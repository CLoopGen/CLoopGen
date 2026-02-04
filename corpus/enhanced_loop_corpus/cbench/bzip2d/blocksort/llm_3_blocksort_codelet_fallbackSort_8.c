#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *bhtab;
extern Int32 ftab[257];
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access via pointer arithmetic
    // Use pointers to traverse ftab and compute indices indirectly.
    // This changes the access pattern to be based on pointer increments rather than indexing.
    Int32 *p = ftab;
    for (i = 0; i < 256; i++) {
        UInt32 value = (UInt32)(*(p + i));
        bhtab[value >> 5] |= (1 << (value & 31));
    }
}
