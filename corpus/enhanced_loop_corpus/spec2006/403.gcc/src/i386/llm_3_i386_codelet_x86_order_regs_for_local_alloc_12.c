#include <stdio.h>

#include <inttypes.h>

extern char call_used_regs[53];
extern int reg_alloc_order[53];
extern int pos;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using a precomputed index array to simulate irregular access pattern
    int indices[53];
    for (int temp_i = 0; temp_i < 53; temp_i++) {
        indices[temp_i] = temp_i;
    }
    for (i = 0; i < 53; i++) {
        int idx = indices[i]; // Indirect access via index array
        if (((idx) < 8 || ((idx) >= (((((20 + 1) + 7) + 1) + 7) + 1) && (idx) <= ((((((20 + 1) + 7) + 1) + 7) + 1) + 7))) && !call_used_regs[idx])
            reg_alloc_order[pos++] = idx;
    }
}
