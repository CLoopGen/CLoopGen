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
    for (i = 0; i < 10; i += 2) {
        int index1 = i;
        int index2 = i + 1;
        if (index2 >= 10) break;

        xpow = (int)(((int64_t)xpow * x + 1073741824) >> 31);

        if ((i & 2) == 0) {
            tmp = (int)(((int64_t)xpow * fixed_log_table[index1] + 1073741824) >> 31);
            ret -= tmp;
        } else {
            tmp = (int)(((int64_t)xpow * fixed_log_table[index2] + 1073741824) >> 31);
            ret += tmp;
            continue;
        }

        xpow = (int)(((int64_t)xpow * x + 1073741824) >> 31);
        tmp = (int)(((int64_t)xpow * fixed_log_table[index2] + 1073741824) >> 31);
        ret += tmp;
    }
}
