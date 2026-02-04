#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int counts[17];
extern int prefixes[18];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via an index array
    // Use a precomputed index map to access arrays in a non-sequential order.
    static const int index_map[16] = {1,3,5,7,9,11,13,15,2,4,6,8,10,12,14,16}; // Odd then even indices
    for (i = 0; i < 16; i++) {
        int idx = index_map[i];
        prefixes[idx + 1] = (prefixes[idx] + counts[idx]) << 1;
    }
}
