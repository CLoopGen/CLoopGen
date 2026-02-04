#include <inttypes.h>

char fixed_regs[53];
char call_used_regs[53];
char regs_ever_live[53];
int i;

void init_vars() {
    for (int j = 0; j < 53; j++) {
        fixed_regs[j] = (j % 7) == 0;
        call_used_regs[j] = (j % 5) != 0;
        regs_ever_live[j] = 0;
    }
}