#include <stdio.h>

#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

extern size_t i;
extern int max_regno;
extern short *reg_renumber;
extern HARD_REG_ELT_TYPE regs_used_so_far;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t indices[] = {53, 55, 57, 59, 61, 63, 65, 67, 69, 71}; // Example indirect access pattern
    size_t num_indices = sizeof(indices) / sizeof(indices[0]);
    for (size_t idx = 0; idx < num_indices; idx++) {
        size_t j = indices[idx];
        if (j < (size_t)max_regno && reg_renumber[j] >= 0)
            ((regs_used_so_far) |= ((HARD_REG_ELT_TYPE)(1)) << (reg_renumber[j]));
    }
}
