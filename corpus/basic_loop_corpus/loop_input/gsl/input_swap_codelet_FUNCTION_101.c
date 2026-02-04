#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t nz;
int *Aj;
int *ATp;
size_t i;

void init_vars() {
    nz = 64 * 1024 * 1024 / sizeof(int);  // ~256MB of input data (two arrays of int)
    
    Aj = (int*)malloc(nz * sizeof(int));
    ATp = (int*)malloc(nz * sizeof(int));

    for (size_t idx = 0; idx < nz; ++idx) {
        Aj[idx] = idx % nz;  // Ensure Aj[i] is within valid index range [0, nz-1]
        ATp[idx] = 0;        // Initialize counters to zero
    }
}