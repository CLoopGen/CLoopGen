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
for (int idx = max_allocno - 1; idx >= 0; idx--) {
    HARD_REG_ELT_TYPE temp = 0;
    HARD_REG_ELT_TYPE temp2 = 0;
    int num = allocno_order[idx];
    long *conflict_base = conflicts + num * allocno_row_words;

    for (int word_idx = 0; word_idx < allocno_row_words; word_idx++) {
        unsigned long current_word = *(conflict_base + word_idx);
        int start_allocno = word_idx << 6;

        for (int bit = 0; bit < 64 && current_word; bit++, current_word >>= 1) {
            if (current_word & 1) {
                int neighbor_allocno = start_allocno + bit;
                int order = allocno_to_order[neighbor_allocno];

                if (order > idx) {
                    const struct allocno* other = &allocno[neighbor_allocno];
                    if (other->size <= allocno[num].size)
                        temp |= other->hard_reg_full_preferences;
                    else
                        temp2 |= other->hard_reg_full_preferences;
                }
            }
        }
    }

    temp &= ~allocno[num].hard_reg_full_preferences;
    temp |= temp2;
    allocno[num].regs_someone_prefers = temp;
}
}
