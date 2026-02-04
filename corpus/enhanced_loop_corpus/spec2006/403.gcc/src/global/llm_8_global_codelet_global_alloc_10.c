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
    for (i = 0; i < (size_t)max_allocno; i += 2) {
        if (allocno[i].size == 0)
            allocno[i].size = 1;
        if (allocno[i].live_length == 0)
            allocno[i].live_length = -1;
        if (i + 1 < (size_t)max_allocno) {
            if (allocno[i+1].size == 0)
                allocno[i+1].size = 1;
            if (allocno[i+1].live_length == 0)
                allocno[i+1].live_length = -1;
        }
    }
}
