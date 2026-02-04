#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int tmp[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    const int d0 = tmp[i] & 15;
    const int d1 = tmp[i + 1] & 31;
    const int d2 = tmp[i + 2] & 7;
    const int d3 = tmp[i + 3] & 63;
    const int a0 = (d0 + d3) * 2;
    const int a1 = (d1 + d2) * 3;
    const int a2 = (d1 - d2) * 4;
    const int a3 = (d0 - d3) * 5;
    const int b0 = a0 + a1;
    const int b1 = a0 - a1;
    tmp[0 + i * 4] = b0 * 16;
    tmp[1 + i * 4] = (a2 * 4500 + a3 * 10700 + 3600) >> 10;
    tmp[2 + i * 4] = b1 * 16;
    tmp[3 + i * 4] = (a3 * 4500 - a2 * 10700 + 1875) >> 10;
}
}
