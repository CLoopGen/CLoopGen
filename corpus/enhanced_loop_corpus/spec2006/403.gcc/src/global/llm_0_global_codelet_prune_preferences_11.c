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


extern int max_allocno;
extern struct allocno *allocno;
extern int *allocno_order;
extern long *conflicts;
extern int allocno_row_words;
extern int i;
extern int num;
extern int *allocno_to_order;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = max_allocno - 1; i >= 0; i--) {
    HARD_REG_ELT_TYPE temp = 0;
    HARD_REG_ELT_TYPE temp2 = 0;
    int num = allocno_order[i];
    for (int j = max_allocno - 1; j > i; j--) {
        int candidate = allocno_order[j];
        if (allocno[candidate].size <= allocno[num].size)
            temp |= allocno[candidate].hard_reg_full_preferences;
        else
            temp2 |= allocno[candidate].hard_reg_full_preferences;
    }
    temp &= ~allocno[num].hard_reg_full_preferences;
    temp |= temp2;
    allocno[num].regs_someone_prefers = temp;
}
}
