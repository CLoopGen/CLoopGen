#include <stdio.h>

#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

extern HARD_REG_ELT_TYPE newpat_used_regs;
extern unsigned int regno;
extern unsigned int endregno;
extern unsigned int r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with unrolled loop (tripled operations per iteration)
    // Unroll factor of 3 applied where possible, reducing loop overhead and increasing arithmetic density
    unsigned int r_limit = endregno - (endregno - regno) % 3; // Align to multiple of 3 for safe unrolling
    for (r = regno; r < r_limit; r += 3) {
        newpat_used_regs |= ((HARD_REG_ELT_TYPE)1) << r;
        newpat_used_regs |= ((HARD_REG_ELT_TYPE)1) << (r + 1);
        newpat_used_regs |= ((HARD_REG_ELT_TYPE)1) << (r + 2);
    }
    // Handle remaining iterations
    for (; r < endregno; r++) {
        newpat_used_regs |= ((HARD_REG_ELT_TYPE)1) << r;
    }
}
