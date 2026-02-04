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
    int limit = max_allocno * 2;
    for (i = 0; i < limit; i += 2) {
        int idx = i / 2;
        if (idx >= max_allocno) break;
        if (reg_renumber[allocno[allocno_order[idx]].reg] >= 0)
            continue;
        if ((allocno[allocno_order[idx]].freq > 100) || (allocno[allocno_order[idx]].live_length > 50)) {
            nregs += 2;
        } else {
            nregs++;
        }
    }
}
