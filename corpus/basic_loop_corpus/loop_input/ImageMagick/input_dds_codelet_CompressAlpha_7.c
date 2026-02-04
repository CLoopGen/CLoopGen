#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

ssize_t *alphas;
unsigned char *indices;
unsigned char codes[8];
size_t error;
size_t _usr_index;
size_t j;
size_t least;
size_t value;
ssize_t i;

#define index _usr_index

void init_vars() {
    // Allocate alphas and indices arrays with 16 elements as implied by loop bound
    alphas = (ssize_t*)malloc(16 * sizeof(ssize_t));
    indices = (unsigned char*)malloc(16 * sizeof(unsigned char));

    // Initialize codes array with sample values (e.g., small increasing values)
    for (int k = 0; k < 8; k++) {
        codes[k] = (unsigned char)(k * 31); // Spread out values in byte range
    }

    // Initialize alphas with mixed values: some -1, others positive
    for (int k = 0; k < 16; k++) {
        if (k % 5 == 0) {
            alphas[k] = -1; // Trigger the continue condition
        } else {
            alphas[k] = (ssize_t)(k * 100 + 42); // Within size_t range when cast
        }
    }

    // Initialize global scalars
    error = 0;
    _usr_index = 0;
    j = 0;
    least = 0;
    value = 0;
    i = 0;
}