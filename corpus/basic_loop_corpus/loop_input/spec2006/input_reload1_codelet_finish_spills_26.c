#include <stdio.h>
#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

char regs_ever_live[53];
int n_spills;
short spill_reg_order[53];
short spill_regs[53];
HARD_REG_ELT_TYPE used_spill_regs;
int num_eliminable;
int something_changed;
int i;

void init_vars() {
    // Initialize scalar variables
    n_spills = 0;
    num_eliminable = 1;
    something_changed = 0;
    i = 0;

    // Initialize arrays to safe default values
    for (int j = 0; j < 53; j++) {
        regs_ever_live[j] = 0;
        spill_reg_order[j] = -2; // Will be overwritten in loop, but initialize anyway
        spill_regs[j] = -1;
    }

    // Set used_spill_regs to a value that will cause approximately half the bits to be set
    // This ensures meaningful branching in the loop without being trivial
    used_spill_regs = 0xAAAAAAAAAAAAAAAALL; // Example bit pattern with alternating bits
}