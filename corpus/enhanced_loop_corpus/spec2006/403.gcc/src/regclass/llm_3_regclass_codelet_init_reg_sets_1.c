#include <stdio.h>

#include <inttypes.h>

extern int reg_alloc_order[53];
extern int inv_reg_alloc_order[53];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array to simulate indirect addressing pattern
    int index_map[53];
    for (i = 0; i < 53; i++)
        index_map[i] = i;  // Simulate precomputed indirect indices

    for (i = 0; i < 53; i++) {
        int pos = index_map[i];  // Indirect access via index_map
        inv_reg_alloc_order[reg_alloc_order[pos]] = pos;
    }
}
