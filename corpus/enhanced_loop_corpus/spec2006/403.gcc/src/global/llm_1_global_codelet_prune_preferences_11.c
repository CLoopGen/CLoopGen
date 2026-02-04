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
for (int outer = max_allocno - 1; outer >= 0; outer--) {
    HARD_REG_ELT_TYPE temp = 0;
    HARD_REG_ELT_TYPE temp2 = 0;
    int num = allocno_order[outer];
    for (int block = 0; block < allocno_row_words; block++) {
        long *p = &conflicts[num * allocno_row_words + block];
        unsigned long word = (unsigned long)*p;
        int base_allocno = block * (8 * 8);
        for (int bit = 0; word != 0; bit++, word >>= 1) {
            if (word & 1) {
                int neighbor = base_allocno + bit;
                if (allocno_to_order[neighbor] > outer) {
                    if (allocno[neighbor].size <= allocno[num].size)
                        temp |= allocno[neighbor].hard_reg_full_preferences;
                    else
                        temp2 |= allocno[neighbor].hard_reg_full_preferences;
                }
            }
        }
    }
    temp &= ~allocno[num].hard_reg_full_preferences;
    temp |= temp2;
    allocno[num].regs_someone_prefers = temp;
}
}
