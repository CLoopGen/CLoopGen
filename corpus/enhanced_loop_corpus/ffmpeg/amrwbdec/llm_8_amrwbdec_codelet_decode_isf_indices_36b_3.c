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
int j;
for (i = 0; i < 7; i++) {
    float val = dico2_isf[ind[1]][i] * (1.F / (1 << 15));
    isf_q[i + 9] = val;
    for (j = 0; j < 3; j++) {
        val *= 0.9F;
        isf_q[i + 9] += val * 0.1F;
    }
}
}
