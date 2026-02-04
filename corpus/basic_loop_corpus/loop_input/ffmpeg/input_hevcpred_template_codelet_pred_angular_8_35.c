#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int mode;
int x;
uint8_t *left;
int inv_angle[32];
uint8_t *ref_tmp;
int last;

void init_vars() {
    // Allocate sufficient data to make the loop run ~0.01 seconds
    // Estimate: 100 million iterations ≈ 0.01s on modern CPU
    const size_t data_size = 134217728; // 128MB total allocation target

    // Ensure mode is in valid range so inv_angle[mode-11] is safe
    mode = 11; // so mode-11 = 0, access inv_angle[0]

    // Allocate left with extra padding for negative indexing
    left = (uint8_t*)calloc(data_size + 256, sizeof(uint8_t));
    if (!left) exit(1);
    // Base accessible index starts at -1 offset, so we need left[-1] valid -> need left[0] at index 1
    uint8_t* left_base = left + 1; // now left[-1] points to left[0]
    left = left_base;

    // Initialize inv_angle array
    for (int i = 0; i < 32; i++) {
        inv_angle[i] = (i + 1) * 100; // arbitrary non-zero values
    }

    // Allocate ref_tmp, size must accommodate indices from 'last' to -1 inclusive
    last = -((int)data_size / 4); // about -33M, so loop runs ~33M times
    ref_tmp = (uint8_t*)calloc(-last + 1, sizeof(uint8_t));
    if (!ref_tmp) exit(1);
    // Adjust so that ref_tmp[x] for x from last to -1 is valid
    ref_tmp -= last; // shift base so that ref_tmp[last] maps to first allocated byte

}