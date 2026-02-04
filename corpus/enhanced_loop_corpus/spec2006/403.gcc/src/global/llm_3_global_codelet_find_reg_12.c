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
    // Variant 2: Consecutive reverse traversal with prefetching pattern
    int idx;
    for (idx = lim - 1; idx >= best_reg; idx--) {
        int j = idx; // Map index to original j
        ((this_reg) |= ((HARD_REG_ELT_TYPE)(1)) << (j));
        ((regs_used_so_far) |= ((HARD_REG_ELT_TYPE)(1)) << (j));
        local_reg_n_refs[j] = 0;
        local_reg_freq[j] = 0;
    }
}
