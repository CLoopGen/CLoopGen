#include <stdio.h>
#include <inttypes.h>

char call_used_regs[53];
int reg_alloc_order[53];
int pos;
int i;

void init_vars() {
    for (int j = 0; j < 53; j++) {
        call_used_regs[j] = (j % 2);  // Alternate used/unused to ensure some condition matches
    }
    pos = 0;
}