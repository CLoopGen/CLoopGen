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
for (i = 0; i < 20; i += 4) {
    xpow = (int)(((int64_t)xpow * x + 1073741824) >> 31);
    tmp = (int)(((int64_t)xpow * fixed_log_table[i % 10] + 1073741824) >> 31);
    ret -= tmp;
    xpow = (int)(((int64_t)xpow * x + 1073741824) >> 31);
    tmp = (int)(((int64_t)xpow * fixed_log_table[(i + 1) % 10] + 1073741824) >> 31);
    ret += tmp;

    xpow = (int)(((int64_t)xpow * x + 1073741824) >> 31);
    tmp = (int)(((int64_t)xpow * fixed_log_table[(i + 2) % 10] + 1073741824) >> 31);
    ret -= tmp;
    xpow = (int)(((int64_t)xpow * x + 1073741824) >> 31);
    tmp = (int)(((int64_t)xpow * fixed_log_table[(i + 3) % 10] + 1073741824) >> 31);
    ret += tmp;
}
}
