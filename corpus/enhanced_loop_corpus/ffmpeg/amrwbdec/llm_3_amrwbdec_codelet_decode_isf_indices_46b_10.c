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
    // Variant 2: Strided memory access using pointer arithmetic (stride of 2, wrapping safely)
    const int16_t *dico_base = &dico22_isf[ind[3]][0];
    for (i = 0; i < 3; i += 1) {
        // Access with artificial stride pattern (e.g., use i*2 % 3 to simulate non-unit stride within bounds)
        int idx = (i * 2) % 3;
        isf_q[i + 3] += dico_base[idx] * (1.F / (1 << 15));
    }
}
