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
for (int j = 0; j < 311; j++) {
    int idx = j;
    x = (mt[idx] & 18446744071562067968ULL) | (mt[idx + 1] & 2147483647ULL);
    mt[idx] = mt[idx + (156 - 312)] ^ (x >> 1) ^ mag01[(int)(x & 1ULL)];
}
}
