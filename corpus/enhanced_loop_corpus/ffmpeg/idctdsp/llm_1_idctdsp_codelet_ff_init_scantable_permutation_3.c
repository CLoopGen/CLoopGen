#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *idct_permutation;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int level1 = 0; level1 < 4; level1++) {
        for (int level2 = 0; level2 < 4; level2++) {
            for (int level3 = 0; level3 < 4; level3++) {
                if (level1 * 16 + level2 * 4 + level3 < 64) {
                    int i = level1 * 16 + level2 * 4 + level3;
                    idct_permutation[i] = (i & 56) | ((i & 6) >> 1) | ((i & 1) << 2);
                }
            }
        }
    }
}
