#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t dico24_isf[32][3];
extern uint16_t *ind;
extern float *isf_q;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 6; i += 2) {
        int idx = i / 2;
        float scale = 1.F / (1 << 14);
        isf_q[idx + 9] += dico24_isf[ind[5]][idx] * scale;
        if (idx + 1 < 3) {
            isf_q[idx + 10] += dico24_isf[ind[5]][idx + 1] * scale;
        }
    }
}
