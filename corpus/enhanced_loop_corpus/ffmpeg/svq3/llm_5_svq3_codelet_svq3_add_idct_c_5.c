#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    const int val0 = block[0 + 4 * i];
    const int val2 = block[2 + 4 * i];
    const int sum = val0 + val2;
    const int diff = val0 - val2;

    if (sum > diff) {
        const int z0 = 13 * sum;
        const int z1 = 13 * diff;
        const int z2 = 7 * block[1 + 4 * i] - 17 * block[3 + 4 * i];
        const int z3 = 17 * block[1 + 4 * i] + 7 * block[3 + 4 * i];
        block[0 + 4 * i] = z0 + z3;
        block[1 + 4 * i] = z1 + z2;
        block[2 + 4 * i] = z1 - z2;
        block[3 + 4 * i] = z0 - z3;
    } else {
        const int alt_z0 = 10 * sum;
        const int alt_z1 = 15 * diff;
        const int alt_z2 = 5 * block[1 + 4 * i] - 20 * block[3 + 4 * i];
        const int alt_z3 = 20 * block[1 + 4 * i] + 5 * block[3 + 4 * i];
        block[0 + 4 * i] = alt_z0 + alt_z3;
        block[1 + 4 * i] = alt_z1 + alt_z2;
        block[2 + 4 * i] = alt_z1 - alt_z2;
        block[3 + 4 * i] = alt_z0 - alt_z3;
    }
}
}
