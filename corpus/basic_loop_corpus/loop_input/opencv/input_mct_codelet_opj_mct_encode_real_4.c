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
    n = 64 * 1024 * 1024 / sizeof(OPJ_FLOAT32);  // ~76.3 MB total for three arrays (~25.4 MB each)

    c0 = (OPJ_FLOAT32*)aligned_alloc(32, n * sizeof(OPJ_FLOAT32));
    c1 = (OPJ_FLOAT32*)aligned_alloc(32, n * sizeof(OPJ_FLOAT32));
    c2 = (OPJ_FLOAT32*)aligned_alloc(32, n * sizeof(OPJ_FLOAT32));

    if (!c0 || !c1 || !c2) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (OPJ_SIZE_T idx = 0; idx < n; ++idx) {
        c0[idx] = 1.0F + (idx % 255) * 0.01F;
        c1[idx] = 0.5F + (idx % 123) * 0.02F;
        c2[idx] = 0.2F + (idx % 89) * 0.03F;
    }

    i = 0;
}