#include <stdio.h>
#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

int n_spills;
short spill_regs[53];
HARD_REG_ELT_TYPE used_spill_regs;
int i;

void init_vars() {
    n_spills = 53;
    used_spill_regs = 0UL;
    for (i = 0; i < n_spills; i++) {
        spill_regs[i] = (short)(i % (sizeof(HARD_REG_ELT_TYPE) * 8));
    }
}