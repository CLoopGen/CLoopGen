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
    unsigned long long prev_x;
    if (i < 312 - 1) {
        x = (mt[i] & 18446744071562067968ULL) | (mt[i + 1] & 2147483647ULL);
        mt[i] = mt[i + (156 - 312)] ^ (x >> 1) ^ mag01[(int)(x & 1ULL)];
        i++;
    }
    for (; i < 312 - 1; i++) {
        prev_x = (mt[i - 1] & 18446744071562067968ULL) | (mt[i] & 2147483647ULL);
        x = (mt[i] & 18446744071562067968ULL) | (mt[i + 1] & 2147483647ULL);
        mt[i] = mt[i + (156 - 312)] ^ (prev_x >> 1) ^ mag01[(int)(prev_x & 1ULL)];
    }
}
