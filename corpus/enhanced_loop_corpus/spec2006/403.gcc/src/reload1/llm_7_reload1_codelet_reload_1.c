#include <stdio.h>

#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

extern int n_spills;
extern short spill_regs[53];
extern HARD_REG_ELT_TYPE used_spill_regs;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_i;
    HARD_REG_ELT_TYPE local_mask = used_spill_regs;
    for (local_i = 0; local_i < n_spills; local_i++) {
        local_mask |= ((HARD_REG_ELT_TYPE)(1)) << spill_regs[local_i];
    }
    used_spill_regs = local_mask;
}
