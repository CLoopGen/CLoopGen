#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned long long mt[312];
extern int i;
extern unsigned long long x;
extern unsigned long long mag01[2];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int j = 0; j < 311; j += 2) {
    int idx1 = j;
    int idx2 = j + 1;
    if (idx2 >= 311) break;
    x = (mt[idx1] & 18446744071562067968ULL) | (mt[idx1 + 1] & 2147483647ULL);
    mt[idx1] = mt[idx1 + (156 - 312)] ^ (x >> 1) ^ mag01[(int)(x & 1ULL)];
    x = (mt[idx2] & 18446744071562067968ULL) | (mt[idx2 + 1] & 2147483647ULL);
    mt[idx2] = mt[idx2 + (156 - 312)] ^ (x >> 1) ^ mag01[(int)(x & 1ULL)];
}
}
