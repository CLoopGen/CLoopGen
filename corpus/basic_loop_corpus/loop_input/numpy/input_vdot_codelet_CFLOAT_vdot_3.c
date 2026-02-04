#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

char *ip1;
npy_intp is1;
char *ip2;
npy_intp is2;
npy_intp n;
float sumr;
float sumi;
npy_intp i;

static char *buffer1 = NULL;
static char *buffer2 = NULL;

void init_vars() {
    const size_t total_size = 64 * 1024 * 1024; // ~64 MB for balanced compute time (~0.01 sec on modern CPU)
    const size_t element_size = sizeof(float) * 2; // complex float: real + imag
    n = total_size / element_size;
    
    // Ensure meaningful computation by having stride equal to element size (contiguous arrays)
    is1 = element_size;
    is2 = element_size;

    // Allocate buffers with proper alignment for float
    buffer1 = (char *)aligned_alloc(32, n * element_size);
    buffer2 = (char *)aligned_alloc(32, n * element_size);

    if (!buffer1 || !buffer2) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize data to prevent NaNs and enable predictable execution
    memset(buffer1, 0, n * element_size);
    memset(buffer2, 0, n * element_size);

    // Set pointers
    ip1 = buffer1;
    ip2 = buffer2;

    // Initialize accumulators
    sumr = 0.0f;
    sumi = 0.0f;
    i = 0;
}