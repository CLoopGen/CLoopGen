#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

#define DATA_SIZE (1024 * 128) // 128KB of data

int p[DATA_SIZE];
int k;
int n;
int d0;
int d1;
unsigned long zz;
unsigned long *z;

void init_vars() {
    // Initialize zz to a non-zero value for meaningful operations
    zz = 0xABCDEF00UL;

    // Allocate z array with sufficient size to prevent out-of-bounds access
    // Each p[k] can write to z[n] and possibly z[n+1], so we need at least (max_n + 2)
    // We'll base allocation on worst-case: p[k] values up to about 8*8*(size_z-2)
    int size_z = (DATA_SIZE / 8) + 100; // Generous upper bound
    z = (unsigned long*)calloc(size_z, sizeof(unsigned long));
    if (!z) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Fill p[] with valid data such that p[k] != 0 during traversal, but terminates eventually
    // We want the loop to run many iterations but terminate naturally
    // Set most entries to non-zero values divisible by powers of 2, then terminate with 0
    int i;
    for (i = 0; i < DATA_SIZE - 1; i++) {
        // Generate spread-out values that are multiples of small numbers
        // Ensure p[k]/64 fits within allocated z range
        p[i] = ((i * 31 + 7) % 512); // Values in [0, 511]
    }
    p[DATA_SIZE - 1] = 0; // Terminate the loop

    // Initialize k to 1 as per loop's starting condition
    k = 1;
}