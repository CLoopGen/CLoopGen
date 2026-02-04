#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *bhtab;
extern Int32 ftab[257];
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index remapping
    // Access ftab elements in reverse order (indirect access pattern using reverse indexing)
    // This creates a non-consecutive, reversed access pattern to stress different memory behavior
    for (i = 0; i < 256; i++) {
        Int32 idx = 255 - i;  // Reverse traversal of ftab
        bhtab[(ftab[idx]) >> 5] |= (1 << ((ftab[idx]) & 31));
    }
}
