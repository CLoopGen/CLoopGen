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
for (i = 0; i < 312 - 156; i++) {
    x = (mt[i] & 18446744071562067968ULL) | (mt[i + 1] & 2147483647ULL);
    mt[i] = mt[i + 156] ^ (x >> 1) ^ mag01[(int)(x & 1ULL)];
}

}
