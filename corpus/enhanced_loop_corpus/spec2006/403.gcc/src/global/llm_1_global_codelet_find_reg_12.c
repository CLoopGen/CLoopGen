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
    if (best_reg < lim) {
        for (j = best_reg; j < lim; j++) {
            ((this_reg) |= ((HARD_REG_ELT_TYPE)(1)) << (j));
            ((regs_used_so_far) |= ((HARD_REG_ELT_TYPE)(1)) << (j));
            local_reg_n_refs[j] = 0;
            local_reg_freq[j] = 0;
            
            // Simulate unrolled second iteration with offset, in case of deeper logic
            int next_j = j + 1;
            if (next_j < lim) {
                ((this_reg) |= ((HARD_REG_ELT_TYPE)(1)) << (next_j));
                ((regs_used_so_far) |= ((HARD_REG_ELT_TYPE)(1)) << (next_j));
                local_reg_n_refs[next_j] = 0;
                local_reg_freq[next_j] = 0;
                j = next_j; // Skip already processed index
            }
        }
    }
}
