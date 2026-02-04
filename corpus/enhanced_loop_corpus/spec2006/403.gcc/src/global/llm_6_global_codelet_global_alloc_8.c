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
    size_t j;
    for (i = 0; i < (size_t)max_allocno; i++) {
        HARD_REG_ELT_TYPE temp_conflicts = allocno[i].hard_reg_conflicts;
        HARD_REG_ELT_TYPE temp_copy_prefs = allocno[i].hard_reg_copy_preferences;
        HARD_REG_ELT_TYPE temp_prefs = allocno[i].hard_reg_preferences;

        temp_conflicts &= ~eliminable_regset;
        temp_copy_prefs &= ~eliminable_regset;
        temp_prefs &= ~eliminable_regset;

        allocno[i].hard_reg_conflicts = temp_conflicts;
        allocno[i].hard_reg_copy_preferences = temp_copy_prefs;
        allocno[i].hard_reg_preferences = temp_prefs;
    }
}
