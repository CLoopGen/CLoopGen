#include <stdio.h>

#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

extern HARD_REG_ELT_TYPE newpat_used_regs;
extern unsigned int regno;
extern unsigned int endregno;
extern unsigned int r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (regno < endregno) {
        r = regno;
        ((newpat_used_regs) |= ((HARD_REG_ELT_TYPE)(1)) << (r));
    }
}
