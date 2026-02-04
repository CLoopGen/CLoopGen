#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N;
void *Y;
int incY;
int i;
int iy;

void init_vars() {
    const size_t total_bytes = 128 * 1024 * 1024; // 128 MB target
    const size_t num_doubles = total_bytes / sizeof(double);
    
    // Ensure we have at least 2 elements per iteration (real and imaginary parts)
    // Each iteration accesses two double values: [2*iy] and [2*iy+1]
    // So total used doubles will be 2 * N
    N = num_doubles / 2;

    Y = aligned_alloc(32, total_bytes);
    if (!Y) {
        exit(1);
    }

    incY = 1; // typical stride
    iy = 0;
}