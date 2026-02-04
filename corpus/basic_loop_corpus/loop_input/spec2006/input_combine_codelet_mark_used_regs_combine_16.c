#include <stdio.h>
#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

HARD_REG_ELT_TYPE newpat_used_regs;
unsigned int regno;
unsigned int endregno;
unsigned int r;

void init_vars() {
    regno = 0;
    endregno = sizeof(HARD_REG_ELT_TYPE) * 8; // Number of bits in the type
    if (endregno > 64) endregno = 64; // Cap at 64 for safety and performance
    newpat_used_regs = 0;
}