#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int fixed_exp_table[7] = {1000, 2000, 3000, 4000, 5000, 6000, 7000};

int x;
int i;
int ret;
int xpow;
int tmp;

void init_vars() {
    x = 500;
    xpow = 1 << 22;
    ret = 0;
    tmp = 0;
    i = 0;
}