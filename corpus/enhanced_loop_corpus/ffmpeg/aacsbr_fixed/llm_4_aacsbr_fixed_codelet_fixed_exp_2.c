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
    for (i = 0; i < 7; i++) {
        if (xpow == 0) continue;
        xpow = (int)(((int64_t)xpow * x + 4194304) >> 23);
        tmp = (int)(((int64_t)xpow * fixed_exp_table[i] + 1073741824) >> 31);
        ret += tmp;
    }
}
