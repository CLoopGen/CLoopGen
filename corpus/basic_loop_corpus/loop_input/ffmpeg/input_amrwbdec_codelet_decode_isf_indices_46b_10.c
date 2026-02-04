#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t dico22_isf[128][3];
uint16_t *ind;
float *isf_q;
int i;

void init_vars() {
    // Allocate large arrays to ensure loop runtime ~0.01s
    // The original loop runs only 3 iterations, so we need to scale data size accordingly.
    // However, the loop itself is minimal; thus, we allocate sufficient memory
    // to allow for potential future unrolling or multiple calls.

    ind = (uint16_t*)calloc(4, sizeof(uint16_t));
    isf_q = (float*)calloc(7, sizeof(float)); // Need at least up to index 5 (i+3 with i=2)

    if (!ind || !isf_q) {
        exit(1);
    }

    // Initialize ind values to valid indices within [0, 127] for dico22_isf
    ind[3] = 0; // Ensure ind[3] is safe for dico22_isf[index][...]

    // Initialize dico22_isf with non-zero values to make computation meaningful
    for (int idx = 0; idx < 128; idx++) {
        for (int j = 0; j < 3; j++) {
            dico22_isf[idx][j] = (int16_t)(idx + j - 64);
        }
    }

    // Initialize isf_q[3..5] to known values to observe changes after loop
    for (int j = 0; j < 6; j++) {
        isf_q[j] = 1.0f;
    }
}