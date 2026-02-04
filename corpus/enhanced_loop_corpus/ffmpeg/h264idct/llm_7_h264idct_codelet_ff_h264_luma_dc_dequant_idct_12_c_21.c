#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int temp[16];
extern int32_t *input;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0, j = 0; i < 4; i++, j += 4) {
        const int z0 = input[j] + input[j + 1];
        const int z1 = input[j] - input[j + 1];
        const int z2 = input[j + 2] - input[j + 3];
        const int z3 = input[j + 2] + input[j + 3];
        temp[j + 0] = z0 + z3;
        temp[j + 1] = z0 - z3;
        temp[j + 2] = z1 - z2;
        temp[j + 3] = z1 + z2;
    }
}
