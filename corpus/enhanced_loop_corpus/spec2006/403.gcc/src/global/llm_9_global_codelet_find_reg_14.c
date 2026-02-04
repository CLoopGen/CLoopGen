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


extern struct allocno *allocno;
extern int allocno_row_words;
extern int j;
extern HARD_REG_ELT_TYPE this_reg;
extern int i_;
extern int allocno_;
extern long *p_;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i_ = (allocno_row_words > 0) ? allocno_row_words - 1 : 0, allocno_ = 0; i_ >= 0; i_--, allocno_ += (16)) {
        unsigned long word1 = (unsigned long)*(p_++);
        unsigned long word2 = (allocno_row_words > 1 && i_ > 0) ? (unsigned long)*(p_++) : 0;
        i_--;
        for (j = allocno_; word1 || word2; word1 >>= 2, word2 >>= 2, j += 2) {
            if (word1 & 1) {
                allocno[j].hard_reg_conflicts |= this_reg;
            }
            if (word2 & 1) {
                allocno[j + 1].hard_reg_conflicts |= this_reg;
            }
        }
    }
}
