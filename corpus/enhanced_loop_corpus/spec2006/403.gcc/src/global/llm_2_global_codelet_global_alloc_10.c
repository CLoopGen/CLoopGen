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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, processing even indices first, then odd if within bounds
    size_t stride = 2;
    for (i = 0; i < (size_t)max_allocno; i += stride) {
        size_t idx1 = i;
        size_t idx2 = i + 1;

        if (idx1 < (size_t)max_allocno) {
            if (allocno[idx1].size == 0)
                allocno[idx1].size = 1;
            if (allocno[idx1].live_length == 0)
                allocno[idx1].live_length = -1;
        }

        if (idx2 < (size_t)max_allocno) {
            if (allocno[idx2].size == 0)
                allocno[idx2].size = 1;
            if (allocno[idx2].live_length == 0)
                allocno[idx2].live_length = -1;
        }
    }
}
