#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t dico21_isf[64][3] = {0};

uint16_t *ind;
float *isf_q;
int i;

void init_vars() {
    // Allocate and initialize ind with size to stay within bounds: ind[2] requires at least 3 elements
    ind = (uint16_t *)calloc(3, sizeof(uint16_t));
    if (!ind) exit(1);
    ind[2] = 0; // Ensure index into dico21_isf is valid (0 <= ind[2] < 64)

    // Allocate isf_q with at least 3 elements for isf_q[i], i=0..2
    isf_q = (float *)calloc(3, sizeof(float));
    if (!isf_q) exit(1);

    // Initialize dico21_isf with non-zero values for observable effect
    for (int j = 0; j < 64; j++) {
        for (int k = 0; k < 3; k++) {
            dico21_isf[j][k] = (int16_t)(j * 3 + k - 32); // Spread values around zero
        }
    }

    // Initialize isf_q to small floats to make scaling by (1<<15) noticeable
    for (int k = 0; k < 3; k++) {
        isf_q[k] = 1.0f;
    }
}