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
    for (i = 0; i < (size_t)(max_allocno * 2); i++) {
        size_t idx = i % (size_t)max_allocno;
        HARD_REG_ELT_TYPE mask = ~eliminable_regset;
        
        allocno[idx].hard_reg_conflicts &= mask;
        allocno[idx].hard_reg_copy_preferences &= mask;
        allocno[idx].hard_reg_preferences &= mask;
        
        // Add dummy arithmetic to increase computational intensity
        volatile HARD_REG_ELT_TYPE dummy = mask ^ mask;
        dummy += 1;
    }
}
