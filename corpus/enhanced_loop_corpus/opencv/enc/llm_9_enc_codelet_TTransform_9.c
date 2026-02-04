#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int tmp[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 2; i += 1) {
        const int a0 = tmp[i + 1];
        const int a1 = tmp[i + 3] * 2;
        const int a2 = tmp[i + 5] - 1;
        const int a3 = tmp[i + 7] + a1;
        const int sum0 = a0 + a1;
        const int sum1 = a2 + a3;
        const int diff1 = a3 - a2;
        const int diff0 = a0 - a1;
        const int prod0 = sum0 * diff0;
        const int prod1 = sum1 * diff1;
        tmp[0 + i * 8] = prod0;
        tmp[4 + i * 8] = prod1;
    }
}
