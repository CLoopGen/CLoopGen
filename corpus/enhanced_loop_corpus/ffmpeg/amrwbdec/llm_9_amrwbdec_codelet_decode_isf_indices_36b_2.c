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
    float offset = 0.001F;
    for (i = 0; i < 18; i++) {
        int j = i % 9;
        isf_q[j] = (dico1_isf[ind[0]][j] * scale) + offset;
        offset *= -1.001F;
    }
}
