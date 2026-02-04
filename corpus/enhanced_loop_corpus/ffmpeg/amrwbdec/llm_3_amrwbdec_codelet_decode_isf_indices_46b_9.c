#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t dico21_isf[64][3];
extern uint16_t *ind;
extern float *isf_q;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access - traverse dico21_isf with a fixed stride over rows
    // We change access pattern to use strided row access starting from ind[2], stepping by a fixed increment (e.g., +8)
    // This simulates a blocked or tiled access pattern useful in cache optimization scenarios
    const int stride = 8;
    int base_index = ind[2];
    for (i = 0; i < 3; i++) {
        int effective_row = (base_index + i * stride) & 63; // Wrap-around within [0,63] using modulo-like masking
        isf_q[i] += dico21_isf[effective_row][i] * (1.F / (1 << 15));
    }
}
