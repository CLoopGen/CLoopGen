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
for (i = 0; i < B && B > 0; i++) {
    for (j = 0; j < N0 && N0 > 0; j++) {
        collapse_mask |= (!!iy[i * N0 + j]) << i;
    }
}
}
