#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t dico1_isf[256][9];
extern uint16_t *ind;
extern float *isf_q;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    isf_q[0] = dico1_isf[ind[0]][0] * (1.F / (1 << 15));
    for (i = 1; i < 9; i++) {
        isf_q[i] = dico1_isf[ind[0]][i] * (1.F / (1 << 15)) + isf_q[i-1] - isf_q[i-1];
    }
}
