#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ldcost = 42;
int t;
int *A;
int *B;
int i;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~64MB for ~0.01s runtime estimate
    t = 8 * 1024 * 1024; // Adjusted to fit within allocated range using negative indices

    A = (int*)aligned_alloc(32, data_size);
    B = (int*)aligned_alloc(32, data_size);

    for (size_t idx = 0; idx < data_size / sizeof(int); ++idx) {
        A[idx] = 0;
    }

    // Ensure B[-i] is valid for i from 1 to t -> need B[-t] to B[-1], so allocate at least t+1 elements before base
    int* B_base = B + t; // Shift base so that B[-i] for i=1..t accesses valid memory
    B = B_base;

    for (int j = 1; j <= t; ++j) {
        B[-j] = rand() % (data_size / sizeof(int)); // valid index into A
    }
}