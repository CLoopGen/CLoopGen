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
    uint32_t temp_mask = collapse_mask;
    for (i = 0; i < B; i++) {
        int base_index = i * N0;
        for (j = 0; j < N0; j++) {
            int index = base_index + j;
            temp_mask |= (!!iy[index]) << i;
        }
    }
    collapse_mask = temp_mask;
}
