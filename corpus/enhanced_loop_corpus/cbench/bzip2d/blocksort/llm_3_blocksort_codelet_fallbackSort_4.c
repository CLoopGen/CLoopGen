#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 ftab[257];
extern Int32 ftabCopy[256];
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index mapping array (simulated via arithmetic)
    // Here, we reverse the access order: copy from last to first element indirectly
    for (i = 0; i < 256; i++) {
        Int32 idx = 255 - i;  // Reverse traversal index
        ftabCopy[idx] = ftab[idx];
    }
}
