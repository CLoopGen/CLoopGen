#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t dico22_isf[128][3];
extern uint16_t *ind;
extern float *isf_q;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with array base offset
    int16_t (*dico_ptr)[3] = &dico22_isf[ind[3]];
    for (i = 0; i < 3; i++) {
        isf_q[i + 3] += (*dico_ptr)[i] * (1.F / (1 << 15));
    }
}
