#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int temp[16];
extern int32_t *input;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    const int x0 = input[4 * i + 0];
    const int x1 = input[4 * i + 1];
    const int x2 = input[4 * i + 2];
    const int x3 = input[4 * i + 3];

    if (x0 >= x1 && x2 >= x3) {
        const int z0 = x0 + x1;
        const int z3 = x2 + x3;
        temp[4 * i + 0] = z0 + z3;
        temp[4 * i + 1] = z0 - z3;
    } else {
        temp[4 * i + 0] = x0;
        temp[4 * i + 1] = x1;
    }

    if (x0 < x1 || x2 < x3) {
        const int z1 = x0 - x1;
        const int z2 = x2 - x3;
        temp[4 * i + 2] = z1 - z2;
        temp[4 * i + 3] = z1 + z2;
    } else {
        temp[4 * i + 2] = x2;
        temp[4 * i + 3] = x3;
    }
}
}
