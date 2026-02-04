#include <stdio.h>

#include <inttypes.h>

extern int mu;
extern int DirectLinks[8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulates irregular access pattern)
    int index_map[8] = {2, 5, 1, 7, 3, 0, 6, 4}; // Arbitrary permutation of indices
    for (mu = 0; mu < 8; mu++) {
        DirectLinks[index_map[mu]] = 0;
    }
}
