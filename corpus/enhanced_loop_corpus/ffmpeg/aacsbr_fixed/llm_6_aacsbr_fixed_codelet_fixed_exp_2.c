#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int fixed_exp_table[7];
extern int x;
extern int i;
extern int ret;
extern int xpow;
extern int tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_ret = ret;
    int local_xpow = xpow;
    for (i = 0; i < 7; i++) {
        int temp_mult = (int)(((int64_t)local_xpow * x + 4194304) >> 23);
        int tmp = (int)(((int64_t)temp_mult * fixed_exp_table[i] + 1073741824) >> 31);
        local_ret += tmp;
        local_xpow = temp_mult;
    }
    ret = local_ret;
    xpow = local_xpow;
}
