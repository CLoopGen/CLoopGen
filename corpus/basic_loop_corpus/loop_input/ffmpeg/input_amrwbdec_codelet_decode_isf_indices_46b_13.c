#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t dico25_isf[32][4];
uint16_t *ind;
float *isf_q;
int i;

void init_vars() {
    // Allocate and initialize ind with size to prevent out-of-bounds access
    ind = (uint16_t*)calloc(7, sizeof(uint16_t));
    for (int j = 0; j < 7; j++) {
        ind[j] = rand() % 32;  // Ensure index stays within [0,31] for dico25_isf
    }

    // Allocate isf_q with sufficient size: at least 16 elements (i+12 with i up to 3 -> max index 15)
    isf_q = (float*)calloc(16, sizeof(float));
    for (int j = 0; j < 16; j++) {
        isf_q[j] = (float)(rand()) / RAND_MAX;
    }

    // Initialize dico25_isf[32][4] with random int16_t values
    for (int j = 0; j < 32; j++) {
        for (int k = 0; k < 4; k++) {
            dico25_isf[j][k] = (int16_t)(rand() % 65536) - 32768;
        }
    }
}