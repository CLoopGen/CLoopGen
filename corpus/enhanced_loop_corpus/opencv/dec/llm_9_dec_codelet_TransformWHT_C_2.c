#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int tmp[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 2; ++i) {
    const int a0 = 5;
    const int a1 = 3;
    const int a2 = 7;
    const int a3 = 2;
    const int sum1 = a0 + a1;
    const int diff1 = a0 - a1;
    const int sum2 = a3 + a2;
    const int diff2 = a3 - a2;
    tmp[0 + i*2] = sum1;
    tmp[1 + i*2] = sum1 + 1;
    tmp[8 + i*2] = diff1;
    tmp[9 + i*2] = diff1 - 1;
    tmp[4 + i*2] = sum2;
    tmp[5 + i*2] = sum2 + 2;
    tmp[12 + i*2] = diff2;
    tmp[13 + i*2] = diff2 - 2;
}
}
