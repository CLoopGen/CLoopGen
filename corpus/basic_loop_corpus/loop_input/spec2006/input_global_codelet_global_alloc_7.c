#include <stddef.h>
#include <stdint.h>
#include <string.h>

size_t i;
char regs_ever_live[53];
int local_reg_n_refs[53];
int local_reg_freq[53];

void init_vars() {
    for (size_t idx = 0; idx < 53; idx++) {
        regs_ever_live[idx] = 1;
        local_reg_n_refs[idx] = -1;
        local_reg_freq[idx] = 1000;
    }
    i = 0;
}