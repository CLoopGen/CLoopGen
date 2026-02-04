#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float OPJ_FLOAT32;
typedef size_t OPJ_SIZE_T;

OPJ_FLOAT32 *restrict c0;
OPJ_FLOAT32 *restrict c1;
OPJ_FLOAT32 *restrict c2;
OPJ_SIZE_T n;
OPJ_SIZE_T i;

void init_vars() {
    const OPJ_SIZE_T data_size = 64 * 1024 * 1024; // ~768 MB total for three arrays (64M * sizeof(float) * 3)
    n = data_size / sizeof(OPJ_FLOAT32); // Number of float elements

    // Allocate memory for the arrays
    c0 = (OPJ_FLOAT32*)aligned_alloc(32, n * sizeof(OPJ_FLOAT32));
    c1 = (OPJ_FLOAT32*)aligned_alloc(32, n * sizeof(OPJ_FLOAT32));
    c2 = (OPJ_FLOAT32*)aligned_alloc(32, n * sizeof(OPJ_FLOAT32));

    // Initialize arrays with non-zero values to allow compiler optimizations to take effect
    for (OPJ_SIZE_T idx = 0; idx < n; ++idx) {
        c0[idx] = (OPJ_FLOAT32)(idx % 256) * 0.5f;
        c1[idx] = (OPJ_FLOAT32)((idx + 17) % 256) * 0.25f;
        c2[idx] = (OPJ_FLOAT32)((idx + 33) % 256) * 0.75f;
    }

    i = 0;
}