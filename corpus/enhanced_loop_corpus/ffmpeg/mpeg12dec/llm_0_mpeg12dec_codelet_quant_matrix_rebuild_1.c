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
    int outer_i;
    int inner_i;
    for (outer_i = 0; outer_i < 8; outer_i++) {
        for (inner_i = 0; inner_i < 8; inner_i++) {
            int idx = outer_i * 8 + inner_i;
            matrix[new_perm[idx]] = temp_matrix[old_perm[idx]];
        }
    }
}
