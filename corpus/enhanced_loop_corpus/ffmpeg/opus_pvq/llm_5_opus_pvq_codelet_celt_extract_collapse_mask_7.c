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
    collapse_mask = 0;
    for (i = 0; i < B && i < 32; i++) {
        int base_index = i * N0;
        int found = 0;
        for (j = 0; j < N0; j++) {
            if (iy[base_index + j] != 0) {
                found = 1;
                break;
            }
        }
        if (found) {
            collapse_mask |= (1U << i);
        }
    }
}
