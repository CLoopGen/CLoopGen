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
    // Variant 2: Strided memory access (reverse order with unit stride)
    for (i = 6; i >= 0; i--) {
        isf_q[i + 9] = dico2_isf[ind[1]][6 - i] * (1.F / (1 << 15));
    }
}
