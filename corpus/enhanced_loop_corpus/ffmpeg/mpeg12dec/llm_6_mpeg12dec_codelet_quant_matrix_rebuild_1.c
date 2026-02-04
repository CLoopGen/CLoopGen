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
    uint16_t temp_buffer[64];
    for (i = 0; i < 64; i++) {
        temp_buffer[i] = temp_matrix[old_perm[i]];
    }
    for (i = 0; i < 64; i++) {
        matrix[new_perm[i]] = temp_buffer[i];
    }
}
