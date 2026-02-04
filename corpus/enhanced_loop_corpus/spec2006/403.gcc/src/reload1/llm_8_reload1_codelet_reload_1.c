#include <stdio.h>

#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

extern int n_spills;
extern short spill_regs[53];
extern HARD_REG_ELT_TYPE used_spill_regs;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < n_spills * 2; i += 2) {
        int idx1 = spill_regs[i];
        HARD_REG_ELT_TYPE mask1 = ((HARD_REG_ELT_TYPE)(1)) << idx1;
        used_spill_regs |= mask1;
        if (i + 1 < n_spills) {
            int idx2 = spill_regs[i + 1];
            HARD_REG_ELT_TYPE mask2 = ((HARD_REG_ELT_TYPE)(1)) << idx2;
            used_spill_regs |= mask2;
        }
    }
}
