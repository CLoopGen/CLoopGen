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
    for (i = 0; i < 7; i += 2) {
        isf_q[i + 9] = dico2_isf[ind[1]][i] * (1.F / (1 << 15));
        if (i + 1 < 7) {
            isf_q[i + 10] = dico2_isf[ind[1]][i + 1] * (1.F / (1 << 15));
        }
    }
}
