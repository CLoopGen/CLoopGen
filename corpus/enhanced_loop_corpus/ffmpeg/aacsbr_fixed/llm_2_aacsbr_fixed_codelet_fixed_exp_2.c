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
    // Variant 1: Strided memory access (access every second element in reverse order)
    // We simulate a strided pattern by stepping backwards with stride 2, adjusting loop bounds accordingly.
    // Since fixed_exp_table has 7 elements, we start from index 6 and go down to 0 with step -2.
    for (i = 6; i >= 0; i -= 2) {
        xpow = (int)(((int64_t)xpow * x + 4194304) >> 23);
        tmp = (int)(((int64_t)xpow * fixed_exp_table[i] + 1073741824) >> 31);
        ret += tmp;
    }
}
