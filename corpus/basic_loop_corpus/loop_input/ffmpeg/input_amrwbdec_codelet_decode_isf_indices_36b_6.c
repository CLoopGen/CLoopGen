#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

#define ARRAY_SIZE_1MB 65536
#define TOTAL_DATA_SIZE (1 << 20) // ~1MB

int16_t dico23_isf_36b[64][7];

uint16_t *ind;
float *isf_q;
int i;

void init_vars() {
    // Allocate isf_q with enough space to access index up to 9+6 = 15 safely
    isf_q = (float *)calloc(16, sizeof(float));
    
    // Allocate ind with at least 5 elements to safely access ind[4]
    ind = (uint16_t *)malloc(5 * sizeof(uint16_t));
    
    // Initialize dico23_isf_36b with dummy data
    for (int idx = 0; idx < 64; idx++) {
        for (int j = 0; j < 7; j++) {
            dico23_isf_36b[idx][j] = (int16_t)(idx * 7 + j - 32);
        }
    }

    // Initialize ind values within valid range [0, 63] since used as index into dico23_isf_36b
    for (int j = 0; j < 5; j++) {
        ind[j] = rand() % 64;
    }

    // Initialize isf_q with some base float values to make accumulation observable
    for (int j = 0; j < 16; j++) {
        isf_q[j] = (float)(j * 0.5);
    }
}