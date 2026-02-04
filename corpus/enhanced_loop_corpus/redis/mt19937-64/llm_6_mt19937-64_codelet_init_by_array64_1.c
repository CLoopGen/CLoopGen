#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned long long mt[312];
extern unsigned long long init_key[];
extern unsigned long long key_length;
extern unsigned long long i;
extern unsigned long long j;
extern unsigned long long k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; k; k--) {
    uint64_t temp = (mt[i - 1] ^ (mt[i - 1] >> 62)) * 3935559000370003845ULL;
    mt[i] = (mt[i] ^ temp) + init_key[j] + j;
    i++;
    j++;
    if (i >= 312) {
        mt[0] = mt[312 - 1];
        i = 1;
    }
    if (j >= key_length)
        j = 0;
}
}
