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
extern HARD_REG_ELT_TYPE eliminable_regset;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t step = 2;
    for (i = 0; i < (size_t)max_allocno; i += step) {
        if (i + 1 < (size_t)max_allocno) {
            allocno[i].hard_reg_conflicts &= ~eliminable_regset;
            allocno[i].hard_reg_copy_preferences &= ~eliminable_regset;
            allocno[i].hard_reg_preferences &= ~eliminable_regset;

            allocno[i+1].hard_reg_conflicts &= ~eliminable_regset;
            allocno[i+1].hard_reg_copy_preferences &= ~eliminable_regset;
            allocno[i+1].hard_reg_preferences &= ~eliminable_regset;
        } else {
            allocno[i].hard_reg_conflicts &= ~eliminable_regset;
            allocno[i].hard_reg_copy_preferences &= ~eliminable_regset;
            allocno[i].hard_reg_preferences &= ~eliminable_regset;
        }
    }
}
