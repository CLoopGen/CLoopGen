#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t dico23_isf_36b[64][7];
extern uint16_t *ind;
extern float *isf_q;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with increased stride (simulating a different access pattern)
    // Instead of accessing consecutive elements in dico23_isf_36b, we use a stride of 2 on the first dimension,
    // wrapping around using modulo to stay within bounds. This changes the source data accessed.
    int stride = 2;
    for (i = 0; i < 7; i++) {
        int index = (ind[4] * stride) % 64;  // Strided access into dico23_isf_36b
        isf_q[i + 9] += dico23_isf_36b[index][i] * (1.F / (1 << 15));
    }
}
