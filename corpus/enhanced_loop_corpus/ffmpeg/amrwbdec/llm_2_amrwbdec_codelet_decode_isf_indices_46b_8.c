#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t dico2_isf[256][7];
extern uint16_t *ind;
extern float *isf_q;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic
    float *isf_ptr = isf_q + 9;
    const int16_t *dico_row = dico2_isf[ind[1]];
    for (i = 0; i < 7; i++) {
        isf_ptr[i] = dico_row[i] * (1.F / (1 << 15));
    }
}
