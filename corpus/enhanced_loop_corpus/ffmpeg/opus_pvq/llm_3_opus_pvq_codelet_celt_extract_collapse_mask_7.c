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
    // Variant 2: Strided memory access with indirect indexing using pointer arithmetic and stride jump
    int *ptr = iy;
    for (i = 0; i < B; i++) {
        for (j = 0; j < N0; j++) {
            collapse_mask |= (!!*(ptr + i + j * B)) << i;  // Access with column-major (strided) pattern
        }
    }
}
