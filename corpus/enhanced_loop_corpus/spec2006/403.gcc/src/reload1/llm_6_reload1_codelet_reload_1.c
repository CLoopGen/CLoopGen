#include <stdio.h>

#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

extern int n_spills;
extern short spill_regs[53];
extern HARD_REG_ELT_TYPE used_spill_regs;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    HARD_REG_ELT_TYPE temp_used = used_spill_regs;
    for (i = 0; i < n_spills; i++) {
        temp_used |= ((HARD_REG_ELT_TYPE)(1)) << spill_regs[i];
    }
    used_spill_regs = temp_used;
}
