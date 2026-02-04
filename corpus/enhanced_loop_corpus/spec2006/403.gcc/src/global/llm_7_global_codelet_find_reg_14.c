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
    unsigned long local_this_reg = this_reg;
    int i_local = allocno_row_words - 1;
    int a_local = 0;
    long *p_copy = p_;

    for (; i_local >= 0; i_local--, a_local += (8 * 8)) {
        unsigned long word_ = (unsigned long)*p_copy++;
        int j_local = a_local;
        while (word_) {
            if (word_ & 1) {
                ((allocno[j_local].hard_reg_conflicts) |= local_this_reg);
            }
            word_ >>= 1;
            j_local++;
        }
    }
    p_ = p_copy;
    i_ = i_local + 1;
    allocno_ = a_local;
}
