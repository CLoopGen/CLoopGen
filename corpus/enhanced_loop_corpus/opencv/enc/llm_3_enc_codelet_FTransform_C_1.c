#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int tmp[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int indices[4] = {3, 1, 2, 0}; // Indirect access pattern
for (i = 0; i < 4; i++) {
    const int idx = indices[i]; // Use indirect indexing
    const int d0 = tmp[0 + idx];
    const int d1 = tmp[4 + idx];
    const int d2 = tmp[8 + idx];
    const int d3 = tmp[12 + idx];
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
