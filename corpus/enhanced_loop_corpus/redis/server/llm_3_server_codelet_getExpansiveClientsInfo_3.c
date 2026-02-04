#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t ClientsPeakMemInput[8];
extern size_t ClientsPeakMemOutput[8];
extern size_t i;
extern size_t o;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (reverse order traversal)
    int index_map[8] = {7, 6, 5, 4, 3, 2, 1, 0}; // Reverse indexing
    for (int j = 0; j < 8; j++) {
        int idx = index_map[j];
        if (ClientsPeakMemInput[idx] > i)
            i = ClientsPeakMemInput[idx];
        if (ClientsPeakMemOutput[idx] > o)
            o = ClientsPeakMemOutput[idx];
    }
}
