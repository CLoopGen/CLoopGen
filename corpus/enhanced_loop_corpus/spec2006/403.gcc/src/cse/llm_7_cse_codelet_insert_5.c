#include <stdio.h>

#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

extern HARD_REG_ELT_TYPE hard_regs_in_table;
extern unsigned int regno;
extern unsigned int endregno;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    HARD_REG_ELT_TYPE local_mask = 0;
    for (i = regno; i < endregno; i++)
        local_mask |= ((HARD_REG_ELT_TYPE)(1)) << i;
    hard_regs_in_table |= local_mask;
}
