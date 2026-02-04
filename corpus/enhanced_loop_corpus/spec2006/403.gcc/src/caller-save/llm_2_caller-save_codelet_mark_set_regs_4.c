#include <stdio.h>

#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

extern HARD_REG_ELT_TYPE this_insn_sets;
extern int regno;
extern int endregno;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern (stride of 2)
    // Although the operation is on a scalar, we simulate strided traversal by incrementing in steps
    for (i = regno; i < endregno; i += 2)
        ((this_insn_sets) |= ((HARD_REG_ELT_TYPE)(1)) << (i));
    
    // Handle remaining index if stride skips the last odd index
    if ((endregno - regno) % 2 != 0 && (regno % 2) == 0 && endregno > regno)
        ((this_insn_sets) |= ((HARD_REG_ELT_TYPE)(1)) << (endregno - 1));
}
