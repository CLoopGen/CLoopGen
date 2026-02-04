#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef unsigned long HARD_REG_ELT_TYPE;

size_t i;
int max_regno = 1048576; // Approximately 1M iterations for ~0.01 sec runtime
short *reg_renumber;
HARD_REG_ELT_TYPE regs_used_so_far;

void init_vars() {
    reg_renumber = (short*)calloc(max_regno, sizeof(short));
    if (!reg_renumber) {
        exit(1);
    }
    for (int j = 53; j < max_regno; j++) {
        reg_renumber[j] = rand() % 64; // Ensure valid bit shift range
    }
    regs_used_so_far = 0;
}