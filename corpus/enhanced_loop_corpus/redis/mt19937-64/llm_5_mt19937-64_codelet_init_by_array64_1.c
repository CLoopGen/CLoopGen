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
    unsigned long long temp = mt[i - 1];
    mt[i] = (mt[i] ^ ((temp ^ (temp >> 62)) * 3935559000370003845ULL)) + init_key[j] + j;
    i = (i + 1) % 312;
    if (i == 0) i = 1;
    j = (j + 1) % (key_length + 1);
}
}
