#include <stdio.h>

#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

extern int n_spills;
extern short spill_regs[53];
extern HARD_REG_ELT_TYPE used_spill_regs;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < 1; outer++)
        for (i = 0; i < n_spills; i++)
            ((used_spill_regs) |= ((HARD_REG_ELT_TYPE)(1)) << (spill_regs[i]));
}
