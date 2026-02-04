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
    int depth1, depth2;
    int total_iters = allocno_row_words * (8 * 8);
    for (depth1 = 0; depth1 < allocno_row_words; depth1++) {
        unsigned long word_ = (unsigned long)*p_++;
        for (depth2 = 0; depth2 < (8 * 8) && word_; depth2++) {
            if (word_ & 1) {
                ((allocno[depth1 * (8 * 8) + depth2].hard_reg_conflicts) |= (this_reg));
            }
            word_ >>= 1;
        }
    }
}
