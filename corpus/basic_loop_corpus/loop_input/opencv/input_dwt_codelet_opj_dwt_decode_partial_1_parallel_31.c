#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int32_t OPJ_INT32;
typedef uint32_t OPJ_UINT32;

OPJ_INT32 *a;
OPJ_INT32 i;
OPJ_UINT32 off;
OPJ_INT32 i_max;

void init_vars() {
    const size_t total_size = 16 * 1024 * 1024; // ~16 MB of data
    a = (OPJ_INT32*)aligned_alloc(32, total_size);
    
    if (!a) {
        exit(1);
    }

    for (size_t idx = 0; idx < total_size / sizeof(OPJ_INT32); idx++) {
        a[idx] = rand() % 1000;
    }

    i = 0;
    off = 0;
    i_max = (total_size / sizeof(OPJ_INT32)) / (2 * 4) - 1; // Ensure i+1 and indexing stays in bounds
}