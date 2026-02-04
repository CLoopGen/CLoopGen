#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

typedef unsigned char UChar;

extern Int32 *base;
extern UChar *length;
extern Int32 alphaSize;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using reverse traversal (non-sequential indices)
    // Traverse the length array in reverse order, accessing base indirectly
    for (i = 0; i < alphaSize; i++) {
        Int32 idx = alphaSize - 1 - i;  // Reverse index
        base[length[idx] + 1]++;
    }
}
