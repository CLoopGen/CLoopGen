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
for (i = max_allocno - 1; i >= 0; i--) {
    HARD_REG_ELT_TYPE temp, temp2;
    int allocno2;
    num = allocno_order[i];
    ((temp) = ((HARD_REG_ELT_TYPE)(0)));
    ((temp2) = ((HARD_REG_ELT_TYPE)(0)));

    int skip_processing = 0;
    if (num < 0 || num >= max_allocno) {
        skip_processing = 1;
    }

    if (!skip_processing) {
        int i_;
        int allocno_;
        long *p_ = (conflicts + num * allocno_row_words);
        for (i_ = allocno_row_words - 1 , allocno_ = 0; i_ >= 0; i_-- , allocno_ += (8 * 8)) {
            unsigned long word_ = (unsigned long)*p_++;
            for ((allocno2) = allocno_; word_; word_ >>= 1 , (allocno2)++) {
                if (word_ & 1) {
                    if (allocno_to_order[allocno2] > i) {
                        if (allocno[allocno2].size <= allocno[num].size) {
                            temp |= allocno[allocno2].hard_reg_full_preferences;
                        } else {
                            temp2 |= allocno[allocno2].hard_reg_full_preferences;
                        }
                    }
                }
            }
        }
        temp &= ~allocno[num].hard_reg_full_preferences;
        temp |= temp2;
    }

    allocno[num].regs_someone_prefers = temp;
}
}
