#include <stdio.h>
#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

HARD_REG_ELT_TYPE current_live_regs;
int first_regno;
int last_regno;
int i;

void init_vars() {
    current_live_regs = 0xFFFFFFFFUL;
    first_regno = 0;
    last_regno = sizeof(HARD_REG_ELT_TYPE) * 8; // Number of bits in HARD_REG_ELT_TYPE
    i = 0;
}