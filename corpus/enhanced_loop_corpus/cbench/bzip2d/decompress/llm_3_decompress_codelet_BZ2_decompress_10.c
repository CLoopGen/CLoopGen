#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

typedef unsigned char UChar;

extern Int32 nGroups;
extern UChar pos[6];
extern UChar v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access - writing in reverse order
    // Still accesses each element once, but in descending index order
    for (v = nGroups - 1; ; v--) {
        pos[v] = v;
        if (v == 0) break;
    }
}
