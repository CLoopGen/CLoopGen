#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t dico1_isf[256][9];
uint16_t *ind;
float *isf_q;
int i;

void init_vars() {
    // Allocate and initialize ind to point to a single uint16_t value
    ind = (uint16_t*)malloc(sizeof(uint16_t));
    if (!ind) exit(1);
    ind[0] = 0; // Ensure index is within [0,255] range for dico1_isf

    // Allocate and initialize isf_q as a float array of size 9
    isf_q = (float*)malloc(9 * sizeof(float));
    if (!isf_q) exit(1);

    // Initialize dico1_isf with non-zero values for meaningful computation
    for (int idx = 0; idx < 256; idx++) {
        for (int j = 0; j < 9; j++) {
            dico1_isf[idx][j] = (int16_t)(idx * 9 + j);
        }
    }

    // Initialize isf_q to zero to ensure defined behavior
    for (int j = 0; j < 9; j++) {
        isf_q[j] = 0.0f;
    }

    i = 0;
}