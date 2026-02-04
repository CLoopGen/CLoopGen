#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

typedef unsigned char UChar;

extern Int32 nGroups;
extern UChar pos[6];
extern UChar v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map
    // Simulates scenarios where access pattern is controlled via lookup table
    UChar index_map[6];
    for (v = 0; v < nGroups; v++) {
        index_map[v] = v; // Direct mapping here, but enables non-sequential or reordered access
    }
    for (v = 0; v < nGroups; v++) {
        pos[index_map[v]] = v;
    }
}
