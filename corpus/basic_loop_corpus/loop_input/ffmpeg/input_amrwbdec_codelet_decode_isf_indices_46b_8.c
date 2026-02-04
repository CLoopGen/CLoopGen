#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t dico2_isf[256][7];
uint16_t *ind;
float *isf_q;
int i;

void init_vars() {
    // Allocate and initialize ind array
    ind = (uint16_t*)malloc(2 * sizeof(uint16_t));
    if (!ind) exit(1);
    ind[0] = 0;
    ind[1] = 128;  // within [0,255] to index dico2_isf safely

    // Allocate isf_q with size 16 to allow access up to index 9+6=15
    isf_q = (float*)malloc(16 * sizeof(float));
    if (!isf_q) exit(1);

    // Initialize dico2_isf with non-zero values for meaningful computation
    for (int idx = 0; idx < 256; idx++) {
        for (int j = 0; j < 7; j++) {
            dico2_isf[idx][j] = (int16_t)(idx + j);
        }
    }

    // Initialize isf_q to zero to ensure defined behavior
    for (int j = 0; j < 16; j++) {
        isf_q[j] = 0.0f;
    }
}