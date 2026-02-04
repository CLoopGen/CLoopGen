#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t **out;
uint8_t *in;
int len;
int channels;
int ch;
int in_bps;
int is;
int os;

void init_vars() {
    channels = 2;
    len = 1048576; // ~1M samples, adjust for ~0.01s runtime
    in_bps = 2;
    is = 2;
    os = 2;

    // Allocate input buffer
    in = (uint8_t*)aligned_alloc(32, len * channels * in_bps);
    if (!in) exit(1);

    // Allocate output array of pointers
    out = (uint8_t**)calloc(channels, sizeof(uint8_t*));
    if (!out) exit(1);

    for (int c = 0; c < channels; c++) {
        out[c] = (uint8_t*)aligned_alloc(32, len * os);
        if (!out[c]) exit(1);
    }

    // Initialize input data to prevent undefined behavior
    for (int i = 0; i < len * channels * in_bps; i++) {
        in[i] = rand() & 0xFF;
    }
}

// Explicitly provide the loop function signature to ensure linkage
extern void loop();