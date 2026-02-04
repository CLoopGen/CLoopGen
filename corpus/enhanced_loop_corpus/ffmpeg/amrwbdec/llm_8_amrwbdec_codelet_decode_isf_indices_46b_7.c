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
    for (i = 0; i < 9; i += 3) {
        isf_q[i]     = dico1_isf[ind[0]][i]     * (1.F / (1 << 15));
        if (i + 1 < 9) isf_q[i + 1] = dico1_isf[ind[0]][i + 1] * (1.F / (1 << 15));
        if (i + 2 < 9) isf_q[i + 2] = dico1_isf[ind[0]][i + 2] * (1.F / (1 << 15));
    }
}
