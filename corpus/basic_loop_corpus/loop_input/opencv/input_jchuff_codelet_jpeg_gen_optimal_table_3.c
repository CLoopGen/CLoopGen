#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

long *freq;
int *nz_index;
int i;
int num_nz_symbols;

void init_vars() {
    // Allocate freq as a long array of 257 elements (as loop runs from 0 to 256)
    freq = (long*)calloc(257, sizeof(long));
    if (!freq) exit(1);

    // Allocate nz_index to store up to 257 non-zero indices
    nz_index = (int*)malloc(257 * sizeof(int));
    if (!nz_index) exit(1);

    // Reset global state
    i = 0;
    num_nz_symbols = 0;

    // Initialize freq with sparse non-zero data to ensure meaningful execution
    // Use a pattern that ensures ~half the entries are non-zero for realistic workload
    for (int idx = 0; idx < 257; idx++) {
        // Set every other element to a non-zero value to generate sufficient nz entries
        if (idx % 2 == 0) {
            freq[idx] = (long)(idx + 1) * 1000;
        } else {
            freq[idx] = 0;
        }
    }
}