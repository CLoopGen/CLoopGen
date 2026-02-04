#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int fixed_log_table[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int x = 15;
int i = 0;
int ret = 100;
int xpow = 1;
int tmp = 0;

void init_vars() {
    x = 15;
    i = 0;
    ret = 100;
    xpow = 1;
    tmp = 0;

    for (int idx = 0; idx < 10; ++idx) {
        fixed_log_table[idx] = (idx + 1) * 3;
    }
}