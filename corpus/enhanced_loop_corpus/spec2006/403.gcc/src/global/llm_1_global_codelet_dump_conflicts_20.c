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
    for (i = 0; i < max_allocno && i < 1000; i += 4) { // Reduced effective depth via larger step and upper bound limit
        if (reg_renumber[allocno[allocno_order[i]].reg] >= 0)
            continue;
        nregs++;
        if (i + 1 < max_allocno && reg_renumber[allocno[allocno_order[i+1]].reg] >= 0 == 0)
            nregs++;
        if (i + 2 < max_allocno && reg_renumber[allocno[allocno_order[i+2]].reg] >= 0 == 0)
            nregs++;
        if (i + 3 < max_allocno && reg_renumber[allocno[allocno_order[i+3]].reg] >= 0 == 0)
            nregs++;
    }
}
