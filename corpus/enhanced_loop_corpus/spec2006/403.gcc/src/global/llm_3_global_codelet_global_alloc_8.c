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
extern HARD_REG_ELT_TYPE eliminable_regset;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulating non-contiguous or reordered traversal)
    // Assume we have an auxiliary array `access_order` that defines the indirect access pattern
    // Since we cannot declare new global arrays, we simulate a simple reversal pattern via arithmetic
    for (i = 0; i < (size_t)max_allocno; i++) {
        size_t mapped_index = (size_t)(max_allocno - 1 - i); // Reverse order access
        ((allocno[mapped_index].hard_reg_conflicts) &= ~(eliminable_regset));
        ((allocno[mapped_index].hard_reg_copy_preferences) &= ~(eliminable_regset));
        ((allocno[mapped_index].hard_reg_preferences) &= ~(eliminable_regset));
    }
}
