#include <stdio.h>

#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

extern HARD_REG_ELT_TYPE this_insn_sets;
extern int regno;
extern int endregno;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive access pattern
    // Traverse from endregno-1 down to regno (reverse order), still consecutive but opposite direction
    for (i = endregno - 1; i >= regno; i--)
        ((this_insn_sets) |= ((HARD_REG_ELT_TYPE)(1)) << (i));
}
