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
    if (last >= 0) {
        for (int outer = 0; outer <= last; outer++) {
            const int j = scantable[outer];
            const int perm_j = permutation[j];
            block[perm_j] = temp[j];
        }
    }
}
