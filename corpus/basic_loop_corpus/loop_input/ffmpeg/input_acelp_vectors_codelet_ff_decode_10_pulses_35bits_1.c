#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef struct AMRFixed {
    int n;
    int x[10];
    float y[10];
    int no_repeat_mask;
    int pitch_lag;
    float pitch_fac;
} AMRFixed;

int16_t *fixed_index;
AMRFixed *fixed_sparse;
uint8_t *gray_decode;
int half_pulse_count;
int bits;
int i;
int mask;

void init_vars() {
    // Set parameters to ensure loop runs ~0.01 seconds and stays in bounds
    // Estimate: each iteration does ~10-20 operations; modern CPU does ~3e9 ops/sec
    // So 0.01 sec ≈ 3e7 operations → aim for ~1e6 iterations

    half_pulse_count = 500000;  // i from 0 to 499999

    bits = 15;  // typical bit position for sign extraction
    mask = 0xFF; // ensures index into gray_decode is 0-255

    // Allocate fixed_index: needs at least 2 * half_pulse_count elements
    fixed_index = (int16_t*)calloc(2 * half_pulse_count, sizeof(int16_t));
    if (!fixed_index) exit(1);

    // Allocate gray_decode: size must be at least (mask+1) = 256
    gray_decode = (uint8_t*)malloc(256 * sizeof(uint8_t));
    if (!gray_decode) exit(1);
    for (int idx = 0; idx < 256; idx++) {
        gray_decode[idx] = (uint8_t)(idx ^ (idx >> 1));
    }

    // Allocate fixed_sparse: only one instance needed, but structure has fixed arrays of size 10
    // But our loop writes to indices up to 2*i+1 where i < half_pulse_count
    // However, the structure's x and y arrays are only size 10 → this implies the original loop must not run long!
    // CONTRADICTION: structure has fixed-size arrays of 10, so we can only write up to index 9 in x and y.

    // Therefore, our earlier assumption about data size is wrong.
    // The structure AMRFixed has x[10] and y[10], so we can only safely write indices 0..9.
    // Thus, the loop must run at most 5 iterations (so that 2*i+1 <= 9).

    // We must reduce half_pulse_count to 5 to prevent buffer overflow.
    half_pulse_count = 5;

    // Reallocate fixed_index with new size
    free(fixed_index);
    fixed_index = (int16_t*)calloc(2 * half_pulse_count, sizeof(int16_t));
    if (!fixed_index) exit(1);

    // Initialize fixed_index with safe values
    for (int idx = 0; idx < 2 * half_pulse_count; idx++) {
        fixed_index[idx] = rand() & 0xFFFF;  // random 16-bit values
    }

    // Reallocate gray_decode for 256 bytes
    free(gray_decode);
    gray_decode = (uint8_t*)malloc(256 * sizeof(uint8_t));
    if (!gray_decode) exit(1);
    for (int idx = 0; idx < 256; idx++) {
        gray_decode[idx] = (uint8_t)(idx ^ (idx >> 1));  // standard Gray code decode
    }

    // Allocate fixed_sparse
    fixed_sparse = (AMRFixed*)calloc(1, sizeof(AMRFixed));
    if (!fixed_sparse) exit(1);

    // Initialize other scalar variables
    bits = 15;
    mask = 0x8000;  // now mask selects bit 15 for sign

    // Ensure initial state
    i = 0;
}