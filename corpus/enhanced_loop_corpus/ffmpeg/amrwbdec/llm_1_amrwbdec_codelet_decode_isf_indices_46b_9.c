#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t dico21_isf[64][3];
extern uint16_t *ind;
extern float *isf_q;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 1; i++) {
        for (int k = 0; k < 3; k++)
            isf_q[k] += dico21_isf[ind[2]][k] * (1.F / (1 << 15));
    }
}
