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
extern int regno;
extern int j;
extern int i_;
extern int allocno_;
extern long *p_;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    HARD_REG_ELT_TYPE reg_mask = ((HARD_REG_ELT_TYPE)(1)) << regno;
    for (i_ = allocno_row_words - 1, allocno_ = 0; i_ >= 0; i_--, allocno_ += (8 * 8)) {
        unsigned long word_ = (unsigned long)*p_++;
        int local_j = allocno_;
        while (word_) {
            if (word_ & 1) {
                allocno[local_j].hard_reg_conflicts |= reg_mask;
            }
            word_ >>= 1;
            local_j++;
        }
    }
}
