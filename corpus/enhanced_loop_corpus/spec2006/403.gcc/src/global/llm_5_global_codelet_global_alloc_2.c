#include <stdio.h>

#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

extern size_t i;
extern int max_regno;
extern short *reg_renumber;
extern HARD_REG_ELT_TYPE regs_used_so_far;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 53; i < (size_t)max_regno; i++) {
        if (reg_renumber[i] >= 0) {
            if ((reg_renumber[i] & 1) == 0) {
                regs_used_so_far |= (HARD_REG_ELT_TYPE)1 << reg_renumber[i];
            } else {
                regs_used_so_far |= (HARD_REG_ELT_TYPE)1 << reg_renumber[i];
            }
        }
    }
}
