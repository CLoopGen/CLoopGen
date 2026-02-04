#include <stdio.h>

#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

extern char regs_ever_live[53];
extern int n_spills;
extern short spill_reg_order[53];
extern short spill_regs[53];
extern HARD_REG_ELT_TYPE used_spill_regs;
extern int num_eliminable;
extern int something_changed;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_spill_order[53];
    int temp_n_spills = n_spills;
    for (i = 0; i < 53; i++) {
        HARD_REG_ELT_TYPE mask = ((HARD_REG_ELT_TYPE)(1)) << i;
        if (((used_spill_regs) & mask)) {
            temp_spill_order[i] = temp_n_spills;
            spill_regs[temp_n_spills++] = i;
            if (num_eliminable && !regs_ever_live[i])
                something_changed = 1;
            regs_ever_live[i] = 1;
        } else {
            temp_spill_order[i] = -1;
        }
    }
    // Resolve WAW dependency by writing spill_reg_order after full computation
    for (i = 0; i < 53; i++) {
        spill_reg_order[i] = temp_spill_order[i];
    }
    n_spills = temp_n_spills;
}
