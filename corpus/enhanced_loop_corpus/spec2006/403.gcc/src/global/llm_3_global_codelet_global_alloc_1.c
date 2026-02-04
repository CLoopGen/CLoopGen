#include <stdio.h>

#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

extern size_t i;
extern char call_used_regs[53];
extern char regs_ever_live[53];
extern HARD_REG_ELT_TYPE regs_used_so_far;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using a precomputed index array to simulate non-sequential access
    size_t indices[53];
    for (size_t j = 0; j < 53; j++)
        indices[j] = 52 - j;  // Reverse order access: 52, 51, ..., 0

    for (size_t k = 0; k < 53; k++) {
        size_t idx = indices[k];
        if (regs_ever_live[idx] || call_used_regs[idx])
            ((regs_used_so_far) |= ((HARD_REG_ELT_TYPE)(1)) << (idx));
    }
}
