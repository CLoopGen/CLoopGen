#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

int16_t dico1_isf[256][9];
uint16_t *ind;
float *isf_q;
int i;

void init_vars() {
    // Initialize dico1_isf with non-zero values for realism
    for (int idx = 0; idx < 256; idx++) {
        for (int j = 0; j < 9; j++) {
            dico1_isf[idx][j] = (int16_t)(idx * 9 + j - 128);
        }
    }

    // Allocate ind to point to a single uint16_t value within valid range [0, 255]
    ind = (uint16_t*)malloc(sizeof(uint16_t));
    if (!ind) exit(1);
    ind[0] = 128;  // Valid index in [0,255]

    // Allocate isf_q as a float array of size 9
    isf_q = (float*)malloc(9 * sizeof(float));
    if (!isf_q) exit(1);
    for (int j = 0; j < 9; j++) {
        isf_q[j] = 0.0f;
    }
}