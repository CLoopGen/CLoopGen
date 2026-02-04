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
    size_t idx = i & 311; // Ensure index within bounds using bitwise AND for speed
    mt[idx] = (mt[idx] ^ ((mt[(idx - 1) & 311] ^ (mt[(idx - 1) & 311] >> 62)) * 3935559000370003845ULL)) + init_key[j] + j;
    i++;
    j++;
    if (j >= key_length)
        j = 0;
}
}
