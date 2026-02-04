#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

int size;
float *l;
float *u;
float *m;
int i;
int j;
int k;

void init_vars() {
    // Estimate size to achieve ~0.01s runtime
    // The triple loop has roughly O(n^3) operations, each with a multiply and memory access
    // On modern CPUs, aim for problem size that results in several hundred million operations
    // Empirical testing suggests size ~400-600 gives around 0.01s on typical hardware
    
    size = 512;
    
    // Allocate arrays: l[size][size], u[size][size], m[size][size]
    l = (float*)aligned_alloc(32, size * size * sizeof(float));
    u = (float*)aligned_alloc(32, size * size * sizeof(float));
    m = (float*)aligned_alloc(32, size * size * sizeof(float));
    
    if (!l || !u || !m) {
        // Fallback allocation if aligned_alloc fails
        if (!l) l = (float*)malloc(size * size * sizeof(float));
        if (!u) u = (float*)malloc(size * size * sizeof(float));
        if (!m) m = (float*)malloc(size * size * sizeof(float));
    }
    
    // Initialize all memory to avoid NaN or extreme values
    for (int idx = 0; idx < size * size; idx++) {
        l[idx] = 1.0f + (idx % 256) * 0.01f;
        u[idx] = 0.5f + (idx % 128) * 0.02f;
        m[idx] = 0.0f;
    }
}