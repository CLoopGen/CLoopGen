#include <stdio.h>

#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

extern HARD_REG_ELT_TYPE newpat_used_regs;
extern unsigned int regno;
extern unsigned int endregno;
extern unsigned int r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern (stride of 2)
    // Though the operation is on a scalar, we simulate strided traversal by stepping in increments
    for (r = regno; r < endregno; r += 2)
        ((newpat_used_regs) |= ((HARD_REG_ELT_TYPE)(1)) << (r));
    
    // Handle remaining element if endregno - regno is odd
    if ((endregno - regno) % 2 != 0 && (regno % 2) == (endregno - 1) % 2)
        ((newpat_used_regs) |= ((HARD_REG_ELT_TYPE)(1)) << (endregno - 1));
}
