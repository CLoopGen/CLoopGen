#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t dico22_isf_36b[128][4];
extern uint16_t *ind;
extern float *isf_q;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float acc = 0.0f;
    for (i = 0; i < 4; i++) {
        acc += dico22_isf_36b[ind[3]][i] * (1.F / (1 << 15));
        isf_q[i + 5] += acc;
        acc = 0.0f; // Reset to isolate dependency per iteration
    }
}
