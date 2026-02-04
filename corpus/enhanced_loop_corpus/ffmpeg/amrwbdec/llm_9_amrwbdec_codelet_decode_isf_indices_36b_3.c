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
for (i = 0; i < 14; i += 2) {
    int idx = i >> 1;
    float scale = 1.F / (1 << 15);
    isf_q[idx + 9] = dico2_isf[ind[1]][idx] * scale;
    if (idx + 1 < 7) {
        isf_q[idx + 10] = dico2_isf[ind[1]][idx + 1] * scale;
    }
}
}
