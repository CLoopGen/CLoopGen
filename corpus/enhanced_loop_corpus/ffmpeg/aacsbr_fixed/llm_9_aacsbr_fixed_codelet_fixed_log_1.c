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
for (i = 0; i < 5; i++) {
    int64_t scaled_xpow = (int64_t)xpow * x;
    xpow = (int)((scaled_xpow + 1073741824) >> 31);
    int64_t product1 = (int64_t)xpow * fixed_log_table[i];
    int64_t product2 = (int64_t)xpow * fixed_log_table[9 - i];
    tmp = (int)((product1 + 1073741824) >> 31);
    ret -= tmp;
    tmp = (int)((product2 + 1073741824) >> 31);
    ret += tmp;
}
}
