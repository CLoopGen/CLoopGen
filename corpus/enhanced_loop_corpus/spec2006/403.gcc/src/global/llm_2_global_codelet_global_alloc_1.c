#include <stdio.h>

#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

extern size_t i;
extern char call_used_regs[53];
extern char regs_ever_live[53];
extern HARD_REG_ELT_TYPE regs_used_so_far;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2, unrolled to process two elements per iteration
    size_t i;
    for (i = 0; i < 53; i += 2) {
        size_t idx1 = i;
        size_t idx2 = i + 1;
        
        if (idx1 < 53 && (regs_ever_live[idx1] || call_used_regs[idx1]))
            ((regs_used_so_far) |= ((HARD_REG_ELT_TYPE)(1)) << (idx1));
            
        if (idx2 < 53 && (regs_ever_live[idx2] || call_used_regs[idx2]))
            ((regs_used_so_far) |= ((HARD_REG_ELT_TYPE)(1)) << (idx2));
    }
}
