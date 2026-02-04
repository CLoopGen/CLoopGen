#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int32_t OPJ_INT32;
typedef uint32_t OPJ_UINT32;

OPJ_INT32 *restrict tmp;
OPJ_UINT32 c;

void init_vars() {
    const size_t total_size = 16 * 1024 * 1024; // ~16 MB to ensure non-trivial runtime
    tmp = (OPJ_INT32*)aligned_alloc(32, total_size * sizeof(OPJ_INT32));
    if (!tmp) {
        exit(1);
    }

    for (size_t i = 0; i < total_size; ++i) {
        tmp[i] = rand() % 1000 - 500;
    }
}