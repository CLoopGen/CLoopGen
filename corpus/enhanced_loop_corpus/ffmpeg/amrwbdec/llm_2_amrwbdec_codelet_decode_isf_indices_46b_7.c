#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t dico1_isf[256][9];
extern uint16_t *ind;
extern float *isf_q;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with increased stride (simulating non-unit stride)
    // Here, we access every second element in a conceptual extended array layout,
    // but since the original data is fixed, we simulate strided behavior by index manipulation.
    // Note: We still write to consecutive isf_q[i], but read with effective stride in dico1_isf via ind[0] base.
    for (i = 0; i < 9; i += 2) {
        isf_q[i] = dico1_isf[ind[0]][i] * (1.F / (1 << 15));
        if (i + 1 < 9) {
            isf_q[i + 1] = dico1_isf[ind[0]][i + 1] * (1.F / (1 << 15));
        }
    }
}
