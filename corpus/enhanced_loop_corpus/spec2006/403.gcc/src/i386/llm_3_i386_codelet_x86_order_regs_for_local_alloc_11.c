#include <stdio.h>

#include <inttypes.h>

extern char call_used_regs[53];
extern int reg_alloc_order[53];
extern int pos;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via a precomputed index array to alter access pattern
    int indices[53];
    for (i = 0; i < 53; i++) {
        indices[i] = (i * 11) % 53;  // Generate strided indirect indices with wrap-around (prime stride)
    }
    for (i = 0; i < 53; i++) {
        int idx = indices[i];  // Use indirection
        if (((idx) < 8 || ((idx) >= (((((20 + 1) + 7) + 1) + 7) + 1) && (idx) <= ((((((20 + 1) + 7) + 1) + 7) + 1) + 7))) && call_used_regs[idx])
            reg_alloc_order[pos++] = idx;
    }
}
