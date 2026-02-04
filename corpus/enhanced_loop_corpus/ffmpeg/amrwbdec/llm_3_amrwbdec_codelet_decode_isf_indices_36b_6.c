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
    // Variant 2: Consecutive and reverse-ordered access to promote spatial locality
    // We reverse the loop order (from 6 down to 0) to change access pattern over isf_q and dico23_isf_36b,
    // promoting different cache behavior while maintaining correctness.
    for (i = 6; i >= 0; i--) {
        isf_q[i + 9] += dico23_isf_36b[ind[4]][i] * (1.F / (1 << 15));
    }
}
