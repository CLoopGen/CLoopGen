#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *input;
int i;
int16_t *coeff;
int64_t pred;

void init_vars() {
    // Allocate input array with size 4 to match loop bounds (accesses indices 0 to 3)
    input = (int32_t*)malloc(4 * sizeof(int32_t));
    if (!input) {
        exit(1);
    }

    // Allocate coeff array with size 4 since loop accesses coeff[0] to coeff[3]
    coeff = (int16_t*)malloc(4 * sizeof(int16_t));
    if (!coeff) {
        free(input);
        exit(1);
    }

    // Initialize input and coeff arrays with sample values
    for (int j = 0; j < 4; j++) {
        input[j] = (int32_t)(j + 1);        // Example: 1, 2, 3, 4
        coeff[j] = (int16_t)(j + 1);         // Example: 1, 2, 3, 4
    }

    // Initialize pred to zero or a base value
    pred = 0;
}