#include <stdio.h>
#include <inttypes.h>

int i;
unsigned long t_d[9];
unsigned long val;
unsigned long tmp;

void init_vars() {
    // Initialize t_d with non-zero values to ensure meaningful computation
    for (int idx = 0; idx < 9; idx++) {
        t_d[idx] = 0xABCDEF00UL + idx;
    }
    val = t_d[0];
    tmp = 0;
    i = 0;
}