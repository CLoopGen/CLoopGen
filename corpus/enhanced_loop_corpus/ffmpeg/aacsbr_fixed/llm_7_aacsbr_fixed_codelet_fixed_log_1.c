#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int fixed_log_table[10];
extern int x;
extern int i;
extern int ret;
extern int xpow;
extern int tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_ret = ret;
    int running_xpow = xpow;
    for (i = 0; i < 10; i += 2) {
        int prod1 = (int)(((int64_t)running_xpow * x + 1073741824) >> 31);
        int tmp1 = (int)(((int64_t)prod1 * fixed_log_table[i] + 1073741824) >> 31);
        int prod2 = (int)(((int64_t)prod1 * x + 1073741824) >> 31);
        int tmp2 = (int)(((int64_t)prod2 * fixed_log_table[i + 1] + 1073741824) >> 31);
        local_ret = local_ret - tmp1 + tmp2;
        running_xpow = prod2;
    }
    ret = local_ret;
    xpow = running_xpow;
}
