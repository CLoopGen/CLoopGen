#include <stdio.h>

#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

extern HARD_REG_ELT_TYPE newpat_used_regs;
extern unsigned int regno;
extern unsigned int endregno;
extern unsigned int r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    HARD_REG_ELT_TYPE temp_reg = newpat_used_regs;
    for (r = regno; r < endregno; r++)
        temp_reg |= ((HARD_REG_ELT_TYPE)(1)) << r;
    newpat_used_regs = temp_reg;
}
