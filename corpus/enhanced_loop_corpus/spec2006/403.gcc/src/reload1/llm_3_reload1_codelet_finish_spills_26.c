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
    // Variant 2: Indirect memory access via an index remapping array to simulate non-sequential traversal
    short index_map[53];
    for (int j = 0; j < 53; j++) {
        index_map[j] = (j * 7 + 13) % 53;  // Generate a pseudo-random but deterministic permutation using linear congruential mapping
    }

    for (int j = 0; j < 53; j++) {
        int i = index_map[j];  // Use indirect indexing
        if (((used_spill_regs) & (((HARD_REG_ELT_TYPE)(1)) << (i)))) {
            spill_reg_order[i] = n_spills;
            spill_regs[n_spills++] = i;
            if (num_eliminable && !regs_ever_live[i])
                something_changed = 1;
            regs_ever_live[i] = 1;
        } else
            spill_reg_order[i] = -1;
    }
}
