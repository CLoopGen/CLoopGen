#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t dico23_isf[128][3];
extern uint16_t *ind;
extern float *isf_q;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with offset indexing
    // Instead of accessing dico23_isf[ind[4]][i], we assume ind[4] is fixed and unroll for spatial locality
    int base_index = ind[4];
    float scale = 1.F / (1 << 15);
    isf_q[6] += dico23_isf[base_index][0] * scale;
    isf_q[7] += dico23_isf[base_index][1] * scale;
    isf_q[8] += dico23_isf[base_index][2] * scale;
}
