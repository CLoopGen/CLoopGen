#include <stdio.h>

#include <inttypes.h>

extern int bit_use[5][2];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulating non-sequential access pattern)
    int index_map[5] = {0, 2, 4, 1, 3}; // Custom access order
    for (j = 0; j < 5; j++) {
        bit_use[index_map[j]][1] = 0;
    }
}
