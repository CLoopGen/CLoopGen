#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t dico23_isf[128][3];
extern uint16_t *ind;
extern float *isf_q;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access pattern across multiple dictionary entries
    // Simulate a strided access by using arithmetic on the index pointer and stepping through dico23_isf
    float scale = 1.F / (1 << 15);
    uint16_t base_offset = ind[4] & 0x7F;  // Ensure within bounds [0,127]
    for (i = 0; i < 3; i++) {
        // Access dico23_isf with a pseudo-stride: alternate row based on i
        int row = (base_offset + i) % 128;  // Strided row access
        isf_q[i + 6] += dico23_isf[row][i] * scale;
    }
}
