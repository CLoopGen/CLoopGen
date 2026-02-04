#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int32_t OPJ_INT32;
typedef uint32_t OPJ_UINT32;

OPJ_INT32 *restrict tmp;
OPJ_UINT32 c;

void init_vars() {
    const size_t total_size = 256 * 1024 * 1024; // ~256MB of data
    tmp = (OPJ_INT32*)aligned_alloc(32, total_size);
    if (!tmp) {
        exit(1);
    }

    const size_t num_elements = total_size / sizeof(OPJ_INT32);
    for (size_t i = 0; i < num_elements; i++) {
        tmp[i] = (OPJ_INT32)(i % 1000);
    }
}