#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int32_t *dst;
int32_t *src0;
int32_t *src1;
int32_t *win;
int len;
int32_t s0;
int32_t s1;
int32_t wi;
int32_t wj;
int32_t i;
int32_t j;

void init_vars() {
    const int target_time_ns = 10000000; // ~10 ms in nanoseconds
    const long double cpu_freq_giga = 3.0; // Assume 3 GHz typical CPU
    const long double operations_per_iter = 10; // Estimate of operations per loop iteration
    const long double estimated_iters = target_time_ns / (operations_per_iter * (1e9 / cpu_freq_giga));
    
    // Each side uses 'len' elements, so total size is 2*len
    len = (int)(estimated_iters) + 1;
    
    // Ensure symmetry and alignment: make len even so that i from -len to -1 and j from len-1 down to 0 are valid
    if (len % 2 != 0) len++;
    
    size_t array_size = (size_t)len * 2; // indices from -len to len-1 => total 2*len elements
    
    // Allocate with extra space for negative indexing
    dst = (int32_t*)aligned_alloc(32, sizeof(int32_t) * array_size);
    src0 = (int32_t*)aligned_alloc(32, sizeof(int32_t) * array_size);
    src1 = (int32_t*)aligned_alloc(32, sizeof(int32_t) * array_size);
    win = (int32_t*)aligned_alloc(32, sizeof(int32_t) * array_size);
    
    // Set base pointers so that index 0 corresponds to the middle
    dst = &dst[len];
    src0 = &src0[len];
    src1 = &src1[len];
    win = &win[len];
    
    // Initialize arrays with non-zero values to avoid trivial optimizations
    for (int idx = -len; idx < len; idx++) {
        src0[idx] = (int32_t)(idx * 789);
        src1[idx] = (int32_t)(idx * 456);
        win[idx] = (int32_t)((idx + 1) * 123);
    }
}