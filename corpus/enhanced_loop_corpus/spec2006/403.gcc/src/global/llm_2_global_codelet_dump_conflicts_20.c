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


extern short *reg_renumber;
extern int max_allocno;
extern struct allocno *allocno;
extern int *allocno_order;
extern int i;
extern int nregs;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, forward traversal
    for (i = 0; i < max_allocno; i += 2) {
        if (reg_renumber[allocno[allocno_order[i]].reg] >= 0)
            continue;
        nregs++;
    }
    // Handle odd-sized max_allocno by checking last element if stride skips it
    if ((max_allocno % 2) == 1 && max_allocno > 0) {
        i = max_allocno - 1;
        if (reg_renumber[allocno[allocno_order[i]].reg] < 0)
            nregs++;
    }
}
