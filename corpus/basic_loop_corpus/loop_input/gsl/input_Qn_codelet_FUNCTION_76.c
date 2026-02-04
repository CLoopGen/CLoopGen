#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int ni;
int *p;
int *q;
int i;
long sump;
long sumq;

void init_vars() {
    // Aim for approximately 64 million elements to target ~0.01 sec runtime
    // assuming ~1-2 ns per iteration on modern CPUs
    ni = 64 * 1024 * 1024 / sizeof(int);  // ~256 MB total data (two arrays)
    
    // Allocate large arrays
    p = (int*)aligned_alloc(32, ni * sizeof(int));
    q = (int*)aligned_alloc(32, ni * sizeof(int));
    
    if (!p || !q) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    
    // Initialize arrays with non-zero values to avoid zero-page optimizations
    for (int j = 0; j < ni; ++j) {
        p[j] = (j % 1000) + 1;
        q[j] = (j % 1000) + 5;
    }
    
    // Initialize accumulators
    sump = 0;
    sumq = 0;
}