#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *input;
int16_t *coeff;
int64_t pred;
int i;

void init_vars() {
    // Allocate input array with size 4 to match loop bounds (accesses indices 0..3)
    input = (int32_t*)malloc(4 * sizeof(int32_t));
    if (!input) exit(1);

    // Allocate coeff array with size 4 since loop accesses coeff[0..3]
    coeff = (int16_t*)malloc(4 * sizeof(int16_t));
    if (!coeff) exit(1);

    // Initialize input and coeff arrays with sample values to ensure defined behavior
    for (int j = 0; j < 4; j++) {
        input[j] = (int32_t)(j + 1);
        coeff[j] = (int16_t)(j + 1);
    }

    // Initialize pred to 0 to ensure deterministic accumulation
    pred = 0;
}