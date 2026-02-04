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
    int temp_n_refs[53] = {0};
    int temp_freq[53] = {0};
    HARD_REG_ELT_TYPE temp_reg_mask = 0;
    for (j = best_reg; j < lim; j++) {
        temp_reg_mask |= ((HARD_REG_ELT_TYPE)(1)) << j;
        temp_n_refs[j] = 0;
        temp_freq[j] = 0;
    }
    this_reg |= temp_reg_mask;
    regs_used_so_far |= temp_reg_mask;
    for (j = best_reg; j < lim; j++) {
        local_reg_n_refs[j] = temp_n_refs[j];
        local_reg_freq[j] = temp_freq[j];
    }
}
