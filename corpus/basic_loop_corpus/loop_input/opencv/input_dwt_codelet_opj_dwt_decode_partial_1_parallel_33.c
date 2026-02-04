#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int32_t OPJ_INT32;
typedef uint32_t OPJ_UINT32;

OPJ_INT32 *a;
OPJ_UINT32 off;

void init_vars() {
    size_t data_size = 1024 * 1024; // ~4MB of data (1M int32 elements)
    a = (OPJ_INT32*)aligned_alloc(32, data_size * sizeof(OPJ_INT32));
    if (!a) {
        exit(1);
    }
    for (size_t i = 0; i < data_size; ++i) {
        a[i] = (OPJ_INT32)(i % 1000) * 2; // Ensure division by 2 is safe and observable
    }
}