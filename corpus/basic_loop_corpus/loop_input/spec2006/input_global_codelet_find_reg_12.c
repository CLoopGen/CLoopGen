#include <stdio.h>
#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

HARD_REG_ELT_TYPE regs_used_so_far;
int local_reg_n_refs[53];
int local_reg_freq[53];
int best_reg;
int lim;
int j;
HARD_REG_ELT_TYPE this_reg;

void init_vars() {
    best_reg = 0;
    lim = 53;
    j = 0;
    this_reg = 0;
    regs_used_so_far = 0;

    for (int i = 0; i < 53; i++) {
        local_reg_n_refs[i] = 0;
        local_reg_freq[i] = 0;
    }
}