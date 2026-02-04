#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int width;
ptrdiff_t in_linesize;
int16_t * u;
int16_t * v;
uint16_t * s;
uint16_t * d;

void init_vars() {
    // Set width to achieve ~0.01 seconds runtime
    // Assume typical modern CPU can do ~1e9 operations/sec -> aim for ~1e7 iterations
    width = 8192;

    // Set in_linesize to control memory layout; must be large enough to avoid out-of-bounds
    in_linesize = 16384;

    // Allocate arrays with sufficient size
    // u and v are index arrays: values must be within valid range for s indexing
    u = (int16_t*)aligned_alloc(32, width * sizeof(int16_t));
    v = (int16_t*)aligned_alloc(32, width * sizeof(int16_t));
    // s is indexed as v[x] * in_linesize + u[x] => max index: (max_v) * in_linesize + max_u
    // Ensure v[x] in [0, some value below in_linesize bound]
    size_t s_size = in_linesize * in_linesize;
    s = (uint16_t*)aligned_alloc(32, s_size * sizeof(uint16_t));
    d = (uint16_t*)aligned_alloc(32, width * sizeof(uint16_t));

    // Initialize u and v such that index into s stays in bounds
    for (int x = 0; x < width; x++) {
        u[x] = rand() % in_linesize;  // u[x] in [0, in_linesize - 1]
        v[x] = rand() % in_linesize;  // v[x] in [0, in_linesize - 1]
    }

    // Initialize s with dummy data
    for (size_t i = 0; i < s_size; i++) {
        s[i] = (uint16_t)(i & 0xFFFF);
    }
}