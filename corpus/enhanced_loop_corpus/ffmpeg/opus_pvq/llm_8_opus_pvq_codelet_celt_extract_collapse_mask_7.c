#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int *iy;
extern uint32_t B;
extern int i;
extern int j;
extern int N0;
extern uint32_t collapse_mask;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t temp_mask = 0;
    for (i = 0; i < B && i < 32; i++) {
        int base_index = i * N0;
        for (j = 0; j < N0; j += 2) {
            if (j + 1 < N0) {
                temp_mask |= (!!iy[base_index + j]) << i;
                temp_mask |= (!!iy[base_index + j + 1]) << i;
            } else {
                temp_mask |= (!!iy[base_index + j]) << i;
            }
        }
    }
    collapse_mask = temp_mask;
}
