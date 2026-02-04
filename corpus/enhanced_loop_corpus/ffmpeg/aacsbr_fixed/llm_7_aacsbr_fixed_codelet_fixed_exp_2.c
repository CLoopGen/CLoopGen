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
    int temp_sum = 0;
    int power_sequence[7];
    power_sequence[0] = xpow;
    for (i = 1; i < 7; i++) {
        power_sequence[i] = (int)(((int64_t)power_sequence[i-1] * x + 4194304) >> 23);
    }
    for (i = 0; i < 7; i++) {
        int tmp = (int)(((int64_t)power_sequence[i] * fixed_exp_table[i] + 1073741824) >> 31);
        temp_sum += tmp;
    }
    ret += temp_sum;
}
