#include <stdio.h>
#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

char fixed_regs[53];
char call_used_regs[53];
int i;
HARD_REG_ELT_TYPE x;

void init_vars() {
    for (i = 0; i < 53; i++) {
        fixed_regs[i] = 0;
        call_used_regs[i] = 0;
    }
    x = 0xFFFFFFFFUL;
    i = 0;
}