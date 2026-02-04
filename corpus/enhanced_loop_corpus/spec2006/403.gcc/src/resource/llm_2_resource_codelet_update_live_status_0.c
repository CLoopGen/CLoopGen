#include <stdio.h>

#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

extern HARD_REG_ELT_TYPE current_live_regs;
extern int first_regno;
extern int last_regno;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern (stride of 2)
    for (i = first_regno; i < last_regno; i += 2)
        ((current_live_regs) &= ~(((HARD_REG_ELT_TYPE)(1)) << (i)));
}
