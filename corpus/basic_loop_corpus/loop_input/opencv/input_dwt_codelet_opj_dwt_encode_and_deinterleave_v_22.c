#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int32_t OPJ_INT32;
typedef uint32_t OPJ_UINT32;

OPJ_INT32 *tmp;
OPJ_UINT32 c;
OPJ_UINT32 i;

void init_vars() {
    const size_t data_size = 16 * 1024 * 1024; // 16 MB of data
    tmp = (OPJ_INT32*)aligned_alloc(32, data_size * sizeof(OPJ_INT32));
    if (!tmp) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        tmp[idx] = (OPJ_INT32)(idx % 512);
    }

    i = 1;
}

__attribute__((destructor))
void cleanup() {
    if (tmp) {
        free(tmp);
    }
}