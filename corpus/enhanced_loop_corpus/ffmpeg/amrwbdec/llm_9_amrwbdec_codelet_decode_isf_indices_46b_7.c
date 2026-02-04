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
    float scale = 1.F / (1 << 15);
    int idx = ind[0];
    for (i = 0; i < 4; i++) {
        isf_q[i] = dico1_isf[idx][i] * scale;
        isf_q[8 - i] = dico1_isf[idx][8 - i] * scale;
    }
    isf_q[4] = dico1_isf[idx][4] * scale; // middle element handled once
}
