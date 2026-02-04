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
    for (i = 0; i < 3; i++) {
        int local_pow1 = (int)(((int64_t)xpow * x + 4194304) >> 23);
        int local_tmp1 = (int)(((int64_t)local_pow1 * fixed_exp_table[i*2] + 1073741824) >> 31);
        int local_pow2 = (int)(((int64_t)local_pow1 * x + 4194304) >> 23);
        int local_tmp2 = (int)(((int64_t)local_pow2 * fixed_exp_table[i*2+1] + 1073741824) >> 31);
        ret += local_tmp1 + local_tmp2;
        xpow = (int)(((int64_t)local_pow2 * x + 4194304) >> 23); // Advance state
    }
    // Handle remaining iteration if needed (i=6)
    if (6 < 7) {
        xpow = (int)(((int64_t)xpow * x + 4194304) >> 23);
        tmp = (int)(((int64_t)xpow * fixed_exp_table[6] + 1073741824) >> 31);
        ret += tmp;
    }
}
