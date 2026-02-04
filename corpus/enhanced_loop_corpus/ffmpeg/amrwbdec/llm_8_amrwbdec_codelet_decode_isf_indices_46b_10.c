#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t dico22_isf[128][3];
extern uint16_t *ind;
extern float *isf_q;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 6; i += 2) {
        int idx = ind[3] % 128;
        float scale = 1.F / (1 << 15);
        isf_q[i + 3] += dico22_isf[idx][i % 3] * scale;
        if (i + 1 < 3) {
            isf_q[i + 4] += dico22_isf[idx][(i + 1) % 3] * scale;
        }
    }
}
