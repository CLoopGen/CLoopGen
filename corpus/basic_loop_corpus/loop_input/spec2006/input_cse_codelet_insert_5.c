#include <stdio.h>
#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

HARD_REG_ELT_TYPE hard_regs_in_table = 0;
unsigned int regno = 0;
unsigned int endregno = 32;
unsigned int i = 0;

void init_vars() {
    regno = 0;
    endregno = 32;
    hard_regs_in_table = 0;
}