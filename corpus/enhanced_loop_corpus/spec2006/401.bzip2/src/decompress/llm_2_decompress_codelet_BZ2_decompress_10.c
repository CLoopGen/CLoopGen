#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

typedef unsigned char UChar;

extern Int32 nGroups;
extern UChar pos[6];
extern UChar v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with reverse traversal
    // Instead of accessing pos[0], pos[1], ..., access every second element backwards
    // to create a strided and reversed access pattern.
    for (v = nGroups - 1; v < nGroups && v != (UChar)-1; v -= 2) {
        pos[v] = v;
        if (v == 0) break; // Prevent underflow when nGroups is 1
    }
    // Handle the case when nGroups is odd by setting pos[0]
    if (nGroups > 0 && (nGroups % 2 == 1)) {
        pos[0] = 0;
    }
}
