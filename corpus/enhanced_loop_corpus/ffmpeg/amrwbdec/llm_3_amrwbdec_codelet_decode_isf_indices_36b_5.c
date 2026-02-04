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
    // Variant 2: Strided memory access with reversed iteration order
    for (i = 3; i >= 0; i--) {
        isf_q[i + 5] += dico22_isf_36b[ind[3]][i] * (1.F / (1 << 15));
    }
}
