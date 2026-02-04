#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *matrix;
extern  uint8_t *old_perm;
extern  uint8_t *new_perm;
extern uint16_t temp_matrix[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 64; i++) {
        if (new_perm[i] % 2 == 0) {
            matrix[new_perm[i]] = temp_matrix[old_perm[i]];
        }
    }
}
