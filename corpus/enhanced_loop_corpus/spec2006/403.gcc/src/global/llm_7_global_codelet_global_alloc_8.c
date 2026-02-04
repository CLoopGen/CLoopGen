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
    if (max_allocno <= 0) return;
    allocno[0].hard_reg_conflicts &= ~eliminable_regset;
    allocno[0].hard_reg_copy_preferences &= ~eliminable_regset;
    allocno[0].hard_reg_preferences &= ~eliminable_regset;

    for (i = 1; i < (size_t)max_allocno; i++) {
        allocno[i].hard_reg_conflicts &= ~(eliminable_regset);
        allocno[i].hard_reg_copy_preferences &= ~(eliminable_regset);
        allocno[i].hard_reg_preferences &= ~(eliminable_regset);

        allocno[i].n_refs += allocno[i-1].n_refs;
        allocno[i].freq += allocno[i-1].freq;
    }
}
