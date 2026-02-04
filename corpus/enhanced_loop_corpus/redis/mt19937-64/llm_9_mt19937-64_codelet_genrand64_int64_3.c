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
    for (i = 0; i < 312 - 200; i += 2) {
        unsigned long long x1 = (mt[i] & 18446744071562067968ULL) | (mt[i + 1] & 2147483647ULL);
        unsigned long long x2 = (mt[i + 1] & 18446744071562067968ULL) | (mt[i + 2] & 2147483647ULL);
        mt[i] = mt[i + 156] ^ (x1 >> 1) ^ mag01[(int)(x1 & 1ULL)];
        mt[i + 1] = mt[i + 157] ^ (x2 >> 1) ^ mag01[(int)(x2 & 1ULL)];
    }
}
