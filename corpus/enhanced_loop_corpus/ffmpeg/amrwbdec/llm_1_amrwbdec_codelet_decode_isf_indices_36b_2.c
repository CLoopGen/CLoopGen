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
    for (i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int idx = i * 3 + j;
            isf_q[idx] = dico1_isf[ind[0]][idx] * (1.F / (1 << 15));
        }
    }
}
