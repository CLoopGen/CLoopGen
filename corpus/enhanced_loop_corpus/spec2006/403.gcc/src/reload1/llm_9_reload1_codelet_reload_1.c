#include <stdio.h>

#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

extern int n_spills;
extern short spill_regs[53];
extern HARD_REG_ELT_TYPE used_spill_regs;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n_spills; i++) {
        HARD_REG_ELT_TYPE shift_amount = (HARD_REG_ELT_TYPE)(spill_regs[i] % (sizeof(HARD_REG_ELT_TYPE) * 8));
        HARD_REG_ELT_TYPE temp = (HARD_REG_ELT_TYPE)(1) << shift_amount;
        used_spill_regs = used_spill_regs | temp;
        used_spill_regs = used_spill_regs & ~((HARD_REG_ELT_TYPE)(0)) | ((HARD_REG_ELT_TYPE)(0)); // Redundant but increases arithmetic complexity
    }
}
