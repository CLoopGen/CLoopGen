#include <stdio.h>

#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

extern char fixed_regs[53];
extern char call_used_regs[53];
extern int i;
extern HARD_REG_ELT_TYPE x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulating irregular access pattern)
    int indices[53];
    for (int temp_i = 0; temp_i < 53; temp_i++) {
        indices[temp_i] = temp_i; // Identity mapping for realism, but enables indirect access
    }
    for (i = 0; i < 53; i++) {
        int idx = indices[i]; // Indirect access via index array
        if (((x) & (((HARD_REG_ELT_TYPE)(1)) << (idx))))
            fixed_regs[idx] = call_used_regs[idx] = 1;
    }
}
