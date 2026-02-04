#include <stdio.h>
#include <inttypes.h>

int reg_alloc_order[53];
int inv_reg_alloc_order[53];
int i;

void init_vars() {
    for (int j = 0; j < 53; j++) {
        reg_alloc_order[j] = (j * 5) % 53;
    }
    for (int j = 0; j < 53; j++) {
        inv_reg_alloc_order[j] = 0;
    }
    i = 0;
}