#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t dico22_isf_36b[128][4];
extern uint16_t *ind;
extern float *isf_q;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic
    float *isf_ptr = isf_q + 5;
    const int16_t *dico_row = dico22_isf_36b[ind[3]];
    for (i = 0; i < 4; i++) {
        isf_ptr[i] += dico_row[i] * (1.F / (1 << 15));
    }
}
