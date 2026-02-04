#include <stdio.h>

#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

extern HARD_REG_ELT_TYPE this_insn_sets;
extern int regno;
extern int endregno;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with unrolled single-step logic and simplified operation
    if (regno < endregno) {
        this_insn_sets |= ((HARD_REG_ELT_TYPE)(1)) << regno;
    }
    // Simulate loop with fixed small range to reduce complexity
    for (i = regno + 1; i < regno + 2 && i < endregno; i++) {
        this_insn_sets |= ((HARD_REG_ELT_TYPE)(1)) << i;
    }
}
