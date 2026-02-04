#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int tmp[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (j = 0; j < 4; ++j) {
    const int idx = j * 4;
    const int d0 = tmp[idx] >> 3;
    const int d1 = ((tmp[idx + 1] << 9) - 937) * 2217;
    const int d2 = d1 ? (d1 / 5352) : 0;
    const int d3 = d0;
    const int a0 = (d0 + d3);
    const int a1 = (d1 + d2);
    const int a2 = (d1 - d2);
    const int a3 = (d0 - d3);
    tmp[0 + j * 4] = (a0 + a1) * 8;
    tmp[1 + j * 4] = (a2 * 2217 + a3 * 5352 + 1812) >> 9;
    tmp[2 + j * 4] = (a0 - a1) * 8;
    tmp[3 + j * 4] = (a3 * 2217 - a2 * 5352 + 937) >> 9;
    i = j;
}
}
