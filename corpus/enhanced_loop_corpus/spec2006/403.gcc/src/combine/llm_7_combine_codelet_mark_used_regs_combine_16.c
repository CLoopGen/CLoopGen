#include <stdio.h>

#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

extern HARD_REG_ELT_TYPE newpat_used_regs;
extern unsigned int regno;
extern unsigned int endregno;
extern unsigned int r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    HARD_REG_ELT_TYPE local_mask = 0;
    for (r = regno; r < endregno; r++) {
        local_mask |= ((HARD_REG_ELT_TYPE)(1)) << r;
        newpat_used_regs |= local_mask; // Introduces WAW and loop-carried dependence on newpat_used_regs
    }
}
