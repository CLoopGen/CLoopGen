#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

size_t j;
size_t incY;
size_t lenY;
double *Y;
size_t jy;

void init_vars() {
    // Estimate parameters for ~0.01s runtime
    // Assume modern CPU can do many iterations in microseconds,
    // so aim for a moderate array size to avoid being too fast

    lenY = 1 << 20;  // 1M elements, about 8MB of data
    incY = 1;        // typical stride
    jy = 0;          // starting index

    // Allocate Y with sufficient size to handle jy + (lenY-1)*incY
    size_t maxYIndex = jy + (lenY > 0 ? (lenY - 1) * incY : 0);
    Y = (double*)aligned_alloc(32, (maxYIndex + 1) * sizeof(double));
    
    if (!Y) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize allocated memory to zero
    memset(Y, 0, (maxYIndex + 1) * sizeof(double));
}