#include <stdio.h>

#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

struct allocno {
    int reg;
    int size;
    int calls_crossed;
    int n_refs;
    int freq;
    int live_length;
    HARD_REG_ELT_TYPE hard_reg_conflicts;
    HARD_REG_ELT_TYPE hard_reg_preferences;
    HARD_REG_ELT_TYPE hard_reg_copy_preferences;
    HARD_REG_ELT_TYPE hard_reg_full_preferences;
    HARD_REG_ELT_TYPE regs_someone_prefers;
};


extern size_t i;
extern int max_allocno;
extern struct allocno *allocno;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t k;
    int prev_reg = 0;
    for (k = 0; k < (size_t)max_allocno; k++) {
        if (allocno[k].size == 0)
            allocno[k].size = 1;
        if (allocno[k].live_length == 0)
            allocno[k].live_length = -1;
        // Introduce loop-carried WAW and RAW dependency via shared variable
        allocno[k].reg = prev_reg + 1;
        prev_reg = allocno[k].reg; // Loop-carried dependency: current depends on previous iteration
    }
}
