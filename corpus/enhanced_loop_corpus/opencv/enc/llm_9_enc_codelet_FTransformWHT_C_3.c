#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t tmp[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 2; i += 1) {
    const int a0 = tmp[i * 4] + 1;
    const int a1 = tmp[i * 4 + 1];
    const int a2 = tmp[i * 4 + 2];
    const int a3 = tmp[i * 4 + 3] - 1;
    const int sum = a0 + a1;
    const int diff = a0 - a1;
    tmp[0 + i * 8] = sum;
    tmp[1 + i * 8] = a3 + a2;
    tmp[2 + i * 8] = a3 - a2;
    tmp[3 + i * 8] = diff;
    tmp[4 + i * 8] = sum + diff;
    tmp[5 + i * 8] = a3 ^ a2;
    tmp[6 + i * 8] = a0 * a1;
    tmp[7 + i * 8] = a3 * a2;
}
}
