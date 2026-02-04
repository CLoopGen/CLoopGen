#include <stdio.h>

#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

extern HARD_REG_ELT_TYPE *regs_live_at;
extern int born_index;
extern int dead_index;
extern int ins;
extern HARD_REG_ELT_TYPE used;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (traverse from high to low index)
    for (ins = dead_index - 1; ins >= born_index; ins--)
        ((used) |= (regs_live_at[ins]));
}
