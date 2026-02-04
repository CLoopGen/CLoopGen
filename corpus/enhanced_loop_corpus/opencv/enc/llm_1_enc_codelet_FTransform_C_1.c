#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int tmp[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 2; i++) {
    for (int k = 0; k < 2; k++) {
        const int idx = i * 2 + k;
        const int d0 = tmp[idx * 4];
        const int d1 = tmp[idx * 4 + 1];
        const int d2 = tmp[idx * 4 + 2];
        const int d3 = tmp[idx * 4 + 3];
        const int a0 = (d0 + d3);
        const int a1 = (d1 + d2);
        const int a2 = (d1 - d2);
        const int a3 = (d0 - d3);
        tmp[0 + idx * 4] = (a0 + a1) * 8;
        tmp[1 + idx * 4] = (a2 * 2217 + a3 * 5352 + 1812) >> 9;
        tmp[2 + idx * 4] = (a0 - a1) * 8;
        tmp[3 + idx * 4] = (a3 * 2217 - a2 * 5352 + 937) >> 9;
    }
}
}
