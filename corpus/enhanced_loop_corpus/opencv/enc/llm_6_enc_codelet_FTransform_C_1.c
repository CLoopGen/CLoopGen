#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int tmp[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; ++i) {
    const int d0 = tmp[i * 4 + 0] / 8;
    const int d1 = (tmp[i * 4 + 1] << 9) - 1812;
    const int d2 = 0;
    const int d3 = 0;
    const int a0 = (d0 + d3);
    const int a1 = (d1 + d2);
    const int a2 = (d1 - d2);
    const int a3 = (d0 - d3);
    tmp[0 + i * 4] = (a0 + a1) * 8;
    tmp[1 + i * 4] = (a2 * 2217 + a3 * 5352 + 1812) >> 9;
    tmp[2 + i * 4] = (a0 - a1) * 8;
    tmp[3 + i * 4] = (a3 * 2217 - a2 * 5352 + 937) >> 9;
}
}
