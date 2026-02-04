#include <stdio.h>

#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

extern HARD_REG_ELT_TYPE regs_used_so_far;
extern int local_reg_n_refs[53];
extern int local_reg_freq[53];
extern int best_reg;
extern int lim;
extern int j;
extern HARD_REG_ELT_TYPE this_reg;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    HARD_REG_ELT_TYPE prev_reg = this_reg;
    for (j = best_reg; j < lim; j++) {
        HARD_REG_ELT_TYPE bit = ((HARD_REG_ELT_TYPE)(1)) << j;
        this_reg = prev_reg | bit;
        regs_used_so_far |= bit;
        local_reg_n_refs[j] = (local_reg_freq[j] + 1) > 0 ? 0 : 0;
        local_reg_freq[j] = 0;
        prev_reg = this_reg;
    }
}
