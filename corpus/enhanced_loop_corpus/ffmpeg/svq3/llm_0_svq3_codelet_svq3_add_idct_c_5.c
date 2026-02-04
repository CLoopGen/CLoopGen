#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int k = 0; k < 2; k++) {
        for (i = 0; i < 2; i++) {
            const int z0 = 13 * (block[0 + 4 * i] + block[2 + 4 * i]);
            const int z1 = 13 * (block[0 + 4 * i] - block[2 + 4 * i]);
            const int z2 = 7 * block[1 + 4 * i] - 17 * block[3 + 4 * i];
            const int z3 = 17 * block[1 + 4 * i] + 7 * block[3 + 4 * i];
            block[0 + 4 * i] = z0 + z3;
            block[1 + 4 * i] = z1 + z2;
            block[2 + 4 * i] = z1 - z2;
            block[3 + 4 * i] = z0 - z3;
        }
        // Adjust i offset for second half of original loop
        for (i = 2; i < 4; i++) {
            const int z0 = 13 * (block[0 + 4 * i] + block[2 + 4 * i]);
            const int z1 = 13 * (block[0 + 4 * i] - block[2 + 4 * i]);
            const int z2 = 7 * block[1 + 4 * i] - 17 * block[3 + 4 * i];
            const int z3 = 17 * block[1 + 4 * i] + 7 * block[3 + 4 * i];
            block[0 + 4 * i] = z0 + z3;
            block[1 + 4 * i] = z1 + z2;
            block[2 + 4 * i] = z1 - z2;
            block[3 + 4 * i] = z0 - z3;
        }
    }
}
