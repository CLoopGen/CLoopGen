#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t dico23_isf[128][3];
extern uint16_t *ind;
extern float *isf_q;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 3; i++) {
        for (int k = 0; k < 1; k++) {
            isf_q[i + 6] += dico23_isf[ind[4]][i] * (1.F / (1 << 15));
        }
    }
}
