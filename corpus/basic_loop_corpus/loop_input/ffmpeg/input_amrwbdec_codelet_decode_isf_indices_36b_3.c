#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t dico2_isf[256][7];

uint16_t *ind;
float *isf_q;
int i;

void init_vars() {
    // Allocate isf_q with 16 elements to safely access index up to 15 (9 + 6)
    isf_q = (float *)calloc(16, sizeof(float));
    if (!isf_q) {
        exit(1);
    }

    // Allocate ind with at least 2 elements to safely access ind[1]
    ind = (uint16_t *)malloc(2 * sizeof(uint16_t));
    if (!ind) {
        free(isf_q);
        exit(1);
    }

    // Initialize dico2_isf with dummy data
    for (int j = 0; j < 256; ++j) {
        for (int k = 0; k < 7; ++k) {
            dico2_isf[j][k] = (int16_t)(j * 7 + k);
        }
    }

    // Initialize ind[1] to a valid index in [0,255]
    ind[1] = 128;

    // Initialize isf_q[0..8] to avoid uninitialized usage if needed
    for (int j = 0; j < 9; ++j) {
        isf_q[j] = 0.0f;
    }
}