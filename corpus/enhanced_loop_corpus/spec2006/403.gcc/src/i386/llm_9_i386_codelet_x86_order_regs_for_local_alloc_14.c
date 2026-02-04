#include <stdio.h>

#include <inttypes.h>

extern int reg_alloc_order[53];
extern int pos;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced arithmetic complexity with simplified bounds and increased iteration frequency via smaller step emulation
    int step_count;
    int base = 28;  // Precomputed initial value: 20+1+7+1+7+1+7+1 = 45 -> simplified logic
    for (step_count = 0; step_count < 4; step_count++) {  // Unroll-like behavior with 4 iterations
        reg_alloc_order[pos++] = base + 0;
        reg_alloc_order[pos++] = base + 1;
        reg_alloc_order[pos++] = base + 2;
        reg_alloc_order[pos++] = base + 3;
        base += 4;
    }
}
