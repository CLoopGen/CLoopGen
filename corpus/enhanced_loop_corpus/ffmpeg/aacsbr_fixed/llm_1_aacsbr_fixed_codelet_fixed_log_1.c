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
    for (int k = 0; k < 5; k++) { // Decreased effective body operations by changing loop structure
        i = k * 2;
        xpow = (int)(((int64_t)xpow * x + 1073741824) >> 31);
        tmp = (int)(((int64_t)xpow * fixed_log_table[i] + 1073741824) >> 31);
        ret -= tmp;
        xpow = (int)(((int64_t)xpow * x + 1073741824) >> 31);
        tmp = (int)(((int64_t)xpow * fixed_log_table[i + 1] + 1073741824) >> 31);
        ret += tmp;
    }
}
