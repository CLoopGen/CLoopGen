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
    for (i = 0; i <= last; i++) {
        const int j = scantable[i];
        if (j >= 0 && j < 64) {
            const int perm_j = permutation[j];
            block[perm_j] = temp[j];
        }
    }
}
