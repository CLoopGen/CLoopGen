#include <inttypes.h>

int target_flags = 33554432;

char fixed_regs[53] = {0};
char call_used_regs[53] = {0};
char regs_ever_live[53] = {0};

int i;
long size;

void init_vars() {
    for (i = 0; i < 53; i++) {
        fixed_regs[i] = (i % 7 == 0);
        call_used_regs[i] = (i % 3 != 0);
        regs_ever_live[i] = 1;
    }
    size = 0;
    target_flags = 33554432;
    i = 0;
}