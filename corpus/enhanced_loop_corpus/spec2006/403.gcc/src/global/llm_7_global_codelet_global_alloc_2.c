#include <stdio.h>

#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

extern size_t i;
extern int max_regno;
extern short *reg_renumber;
extern HARD_REG_ELT_TYPE regs_used_so_far;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t local_i;
    HARD_REG_ELT_TYPE local_regs = regs_used_so_far;
    for (local_i = 53; local_i < (size_t)max_regno; local_i++) {
        if (reg_renumber[local_i] >= 0) {
            local_regs |= ((HARD_REG_ELT_TYPE)(1)) << (reg_renumber[local_i]);
            regs_used_so_far = local_regs; // WAW and WAR dependency introduced: write after write and write after read on regs_used_so_far
        }
    }
}
