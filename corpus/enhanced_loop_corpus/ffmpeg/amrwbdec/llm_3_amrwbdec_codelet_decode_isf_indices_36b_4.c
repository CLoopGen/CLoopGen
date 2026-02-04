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
    // Variant 2: Strided memory access - process elements in reverse order with stride of 1 (reverse traversal)
    const float scale = 1.F / (1 << 15);
    for (i = 4; i >= 0; i--) {
        isf_q[i] += dico21_isf_36b[ind[2]][i] * scale;
    }
}
