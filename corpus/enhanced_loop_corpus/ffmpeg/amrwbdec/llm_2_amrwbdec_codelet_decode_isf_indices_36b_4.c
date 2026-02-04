#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t dico21_isf_36b[128][5];
extern uint16_t *ind;
extern float *isf_q;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic to improve spatial locality
    float *q = isf_q;
    int16_t *d = &dico21_isf_36b[ind[2]][0];
    const float scale = 1.F / (1 << 15);
    for (i = 0; i < 5; i++) {
        q[i] += d[i] * scale;
    }
}
