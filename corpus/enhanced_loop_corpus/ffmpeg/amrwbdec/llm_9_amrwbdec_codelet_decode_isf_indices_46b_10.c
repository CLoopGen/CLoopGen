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
    const float scale = 1.F / (1 << 12); // Reduced shift for higher contribution
    int base_index = ind[3] & 127;
    for (i = 0; i < 3; i++) {
        float val = dico22_isf[base_index][i] * scale;
        isf_q[i + 3] += val;
        isf_q[i + 6] += val * 0.5f; // Additional computation: secondary accumulation with decay
    }
}
