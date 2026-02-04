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
    int temp1 = xpow;
    int temp2;
    for (i = 0; i < 10; i += 2) {
        temp1 = (int)(((int64_t)temp1 * x + 1073741824) >> 31);
        temp2 = (int)(((int64_t)temp1 * fixed_log_table[i] + 1073741824) >> 31);
        ret -= temp2;
        temp1 = (int)(((int64_t)temp1 * x + 1073741824) >> 31);
        temp2 = (int)(((int64_t)temp1 * fixed_log_table[i + 1] + 1073741824) >> 31);
        ret += temp2;
    }
}
