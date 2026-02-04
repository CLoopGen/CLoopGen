#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t dico25_isf[32][4];
extern uint16_t *ind;
extern float *isf_q;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern
    // Instead of accessing dico25_isf[ind[6]][i] with unit stride on i,
    // we reverse the order of access (strided in decreasing order).
    for (i = 3; i >= 0; i--)
        isf_q[i + 12] += dico25_isf[ind[6]][i] * (1.F / (1 << 15));
}
