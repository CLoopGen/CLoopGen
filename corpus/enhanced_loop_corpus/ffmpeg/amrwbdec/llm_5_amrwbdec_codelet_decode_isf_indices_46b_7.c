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
    for (i = 0; i < 9; i++) {
        if (i % 2 == 0) {
            isf_q[i] = dico1_isf[ind[0]][i] * (1.F / (1 << 15));
        } else {
            isf_q[i] = 0.0F;
        }
    }
}
