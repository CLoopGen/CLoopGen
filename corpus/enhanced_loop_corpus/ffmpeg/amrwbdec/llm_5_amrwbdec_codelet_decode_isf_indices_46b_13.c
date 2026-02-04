#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t dico25_isf[32][4];
extern uint16_t *ind;
extern float *isf_q;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i++) {
        if (dico25_isf[ind[6]][i] != 0) {
            isf_q[i + 12] += dico25_isf[ind[6]][i] * (1.F / (1 << 15));
        }
    }
}
