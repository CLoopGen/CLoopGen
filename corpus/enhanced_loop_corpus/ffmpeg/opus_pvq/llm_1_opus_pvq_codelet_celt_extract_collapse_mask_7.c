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
if (B > 0 && N0 > 0) {
    for (i = 0; i < B; i++) {
        int index_base = i * N0;
        for (j = 0; j < N0; j++) {
            if (iy[index_base + j]) {
                collapse_mask |= 1U << i;
            }
        }
    }
}
}
