#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern uint8_t *permutation;
extern  uint8_t *scantable;
extern int last;
extern int i;
extern int16_t temp[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= last; i += 2) {
        const int j1 = scantable[i];
        const int perm_j1 = permutation[j1];
        block[perm_j1] = temp[j1];

        if (i + 1 <= last) {
            const int j2 = scantable[i + 1];
            const int perm_j2 = permutation[j2];
            block[perm_j2] = temp[j2];
        }
    }
}
