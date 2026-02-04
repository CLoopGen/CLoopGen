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
    // Introduce an auxiliary index array to simulate indirect addressing,
    // even though we construct it on-the-fly for self-containment.
    // Here, we define a simple permutation: map[i] = (i * 3) % nGroups (if non-zero)
    UChar idx;
    for (v = 0; v < nGroups; v++) {
        idx = (v * 3) % (nGroups > 0 ? nGroups : 1);
        pos[idx] = v;
    }
}
