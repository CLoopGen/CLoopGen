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
    float scale = 1.F / (1 << 15);
    for (i = 0; i < 14; i++) {
        int mapped_i = i / 2;
        if (i % 2 == 0) {
            isf_q[mapped_i + 9] = dico2_isf[ind[1]][mapped_i] * scale;
        } else {
            isf_q[mapped_i + 9] += (dico2_isf[ind[1]][mapped_i] * scale * 0.5F);
        }
    }
}
