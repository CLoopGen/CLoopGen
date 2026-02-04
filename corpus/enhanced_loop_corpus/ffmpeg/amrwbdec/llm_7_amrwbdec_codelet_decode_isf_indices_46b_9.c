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
    float scale = 1.F / (1 << 15);
    for (i = 0; i < 3; i++) {
        int16_t val = dico21_isf[ind[2]][i];
        isf_q[i] = isf_q[i] + val * scale;
    }
}
