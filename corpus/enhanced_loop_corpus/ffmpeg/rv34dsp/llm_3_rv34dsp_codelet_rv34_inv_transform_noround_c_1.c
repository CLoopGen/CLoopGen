#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern int temp[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int indices[4][4];
for (int j = 0; j < 4; j++)
    for (int k = 0; k < 4; k++)
        indices[j][k] = j + 4 * k;

for (i = 0; i < 4; i++) {
    const int t0 = temp[indices[i][0]], t1 = temp[indices[i][1]];
    const int t2 = temp[indices[i][2]], t3 = temp[indices[i][3]];
    const int z0 = 39 * (t0 + t2);
    const int z1 = 39 * (t0 - t2);
    const int z2 = 21 * t1 - 51 * t3;
    const int z3 = 51 * t1 + 21 * t3;
    block[indices[i][0]] = (z0 + z3) >> 11;
    block[indices[i][1]] = (z1 + z2) >> 11;
    block[indices[i][2]] = (z1 - z2) >> 11;
    block[indices[i][3]] = (z0 - z3) >> 11;
}
}
