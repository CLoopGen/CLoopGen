#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

int i;
int siglen;
double sigamp;
int16_t *signal;

void init_vars() {
    // Set signal length to achieve ~0.01 seconds runtime
    // Empirical testing suggests ~16M int16_t elements (32 MB) is reasonable
    siglen = 16777216; // 2^24 = ~16.7M elements -> 32MB of data
    sigamp = 0.0;

    // Allocate memory for signal
    signal = (int16_t*)aligned_alloc(32, siglen * sizeof(int16_t));
    if (!signal) {
        siglen = 0;
        return;
    }

    // Initialize signal with non-zero values to ensure meaningful computation
    for (int j = 0; j < siglen; j++) {
        signal[j] = (int16_t)(j & 0xFFFF);
    }
}