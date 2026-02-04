#include <stdio.h>

#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

extern size_t i;
extern int max_regno;
extern short *reg_renumber;
extern HARD_REG_ELT_TYPE regs_used_so_far;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t step = 2;
    for (i = 53; i < (size_t)max_regno; i += step)
        if (i < (size_t)max_regno && reg_renumber[i] >= 0)
            ((regs_used_so_far) |= ((HARD_REG_ELT_TYPE)(1)) << (reg_renumber[i]));
}
