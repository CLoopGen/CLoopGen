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
    // Variant 1: Strided memory access with step size of 2
    for (ins = born_index; ins < dead_index; ins += 2)
        ((used) |= (regs_live_at[ins]));
    // Handle potential odd-indexed boundary by accessing last element if needed
    if ((dead_index - born_index) % 2 != 0 && dead_index > born_index)
        used |= regs_live_at[dead_index - 1];
}
