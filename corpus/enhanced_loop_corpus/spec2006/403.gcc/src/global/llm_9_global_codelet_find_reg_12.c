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
int step = 2;
for (j = best_reg; j < lim; j += step) {
    for (int k = 0; k < 3; k++) {
        this_reg |= (HARD_REG_ELT_TYPE)1 << j;
        regs_used_so_far |= (HARD_REG_ELT_TYPE)1 << j;
        local_reg_n_refs[j] = (local_reg_n_refs[j] + 1) * (k + 1);
        local_reg_freq[j] += (k * j);
    }
}
}
