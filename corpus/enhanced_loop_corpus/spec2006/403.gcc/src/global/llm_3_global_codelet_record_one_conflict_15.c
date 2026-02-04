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
    // Variant 2: Strided access pattern with non-unit stride over allocno array
    int stride = 2;
    int limit = allocno_row_words * (8 * 8);
    for (i_ = 0; i_ < limit; i_ += stride) {
        int p_index = i_ / (8 * 8);
        unsigned long word_ = (unsigned long)*(p_ + p_index);
        int bit_pos = i_ % (8 * 8);
        unsigned long shifted_word = word_ >> bit_pos;

        j = i_;
        if (shifted_word & 1) {
            (allocno[j].hard_reg_conflicts) |= (HARD_REG_ELT_TYPE)1 << regno;
        }
    }
}
