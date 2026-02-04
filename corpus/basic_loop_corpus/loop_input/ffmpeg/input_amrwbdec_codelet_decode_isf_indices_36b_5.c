#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t dico22_isf_36b[128][4];
uint16_t *ind;
float *isf_q;
int i;

void init_vars() {
    // Allocate and initialize ind with size 4 to ensure ind[3] is valid
    ind = (uint16_t*)malloc(4 * sizeof(uint16_t));
    for (int j = 0; j < 4; ++j) {
        ind[j] = rand() % 128;  // Ensure indices are within [0, 127] for dico22_isf_36b
    }

    // Allocate and initialize isf_q with size 9 (since we access index i+5 where i < 4 => max index 8)
    isf_q = (float*)malloc(9 * sizeof(float));
    for (int j = 0; j < 9; ++j) {
        isf_q[j] = (float)(rand()) / RAND_MAX;
    }

    // Initialize dico22_isf_36b[128][4] with random int16_t values
    for (int j = 0; j < 128; ++j) {
        for (int k = 0; k < 4; ++k) {
            dico22_isf_36b[j][k] = (int16_t)(rand() % 65536 - 32768);
        }
    }
}