#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int temp[16];
extern int16_t *input;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i++) {
        if (i % 2 == 0) {
            const int z0 = input[4 * i + 0] + input[4 * i + 1];
            const int z1 = input[4 * i + 0] - input[4 * i + 1];
            const int z2 = input[4 * i + 2] - input[4 * i + 3];
            const int z3 = input[4 * i + 2] + input[4 * i + 3];
            temp[4 * i + 0] = z0 + z3;
            temp[4 * i + 1] = z0 - z3;
            temp[4 * i + 2] = z1 - z2;
            temp[4 * i + 3] = z1 + z2;
        } else {
            const int z0 = input[4 * i + 0] - input[4 * i + 1];
            const int z1 = input[4 * i + 0] + input[4 * i + 1];
            const int z2 = input[4 * i + 2] + input[4 * i + 3];
            const int z3 = input[4 * i + 2] - input[4 * i + 3];
            temp[4 * i + 0] = z0 + z3;
            temp[4 * i + 1] = z0 - z3;
            temp[4 * i + 2] = z1 - z2;
            temp[4 * i + 3] = z1 + z2;
        }
    }
}
