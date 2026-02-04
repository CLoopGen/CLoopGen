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
    // Variant 1: Strided Memory Access (stride of 2 with wrap-around handling)
    int stride = 2;
    int end = (312 - 156 + stride - 1) / stride; // Adjust iteration count for stride
    for (i = 0; i < end; i++) {
        int idx = i * stride;
        if (idx >= 312 - 156) break;
        x = (mt[idx] & 18446744071562067968ULL) | (mt[idx + 1] & 2147483647ULL);
        mt[idx] = mt[idx + 156] ^ (x >> 1) ^ mag01[(int)(x & 1ULL)];
    }
}
