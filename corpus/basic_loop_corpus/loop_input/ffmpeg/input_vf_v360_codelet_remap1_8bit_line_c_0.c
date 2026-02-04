#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int width = 1 << 20; // Approximately 1 million elements for ~0.01 sec runtime
ptrdiff_t in_linesize = 1 << 10; // 1K stride to prevent cache aliasing and ensure valid access

int16_t * u;
int16_t * v;
uint8_t * s;
uint8_t * d;

void init_vars() {
    // Allocate arrays with appropriate sizes
    // Ensure that v[x] * in_linesize + u[x] stays within bounds of s
    // Assume u[x] and v[x] are non-negative and within reasonable range
    size_t s_size = (1 << 10) * in_linesize; // 1K rows of in_linesize each
    size_t array_size = width;

    u = (int16_t*)aligned_alloc(32, array_size * sizeof(int16_t));
    v = (int16_t*)aligned_alloc(32, array_size * sizeof(int16_t));
    s = (uint8_t*)aligned_alloc(32, s_size);
    d = (uint8_t*)aligned_alloc(32, array_size * sizeof(uint8_t));

    // Initialize u and v such that indices are valid: v[x] < (s_size / in_linesize)
    int max_v_index = (s_size / in_linesize) - 1;
    for (size_t x = 0; x < array_size; x++) {
        u[x] = rand() % in_linesize;
        v[x] = rand() % max_v_index;
    }

    // Initialize s with dummy data
    for (size_t i = 0; i < s_size; i++) {
        s[i] = rand() & 0xFF;
    }

    // Initialize d to zero
    for (size_t x = 0; x < array_size; x++) {
        d[x] = 0;
    }
}