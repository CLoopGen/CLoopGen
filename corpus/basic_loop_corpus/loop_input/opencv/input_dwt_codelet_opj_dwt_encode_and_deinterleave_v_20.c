#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int32_t OPJ_INT32;
typedef uint32_t OPJ_UINT32;

OPJ_INT32 *restrict tmp;
OPJ_UINT32 c;
OPJ_UINT32 i;

void init_vars() {
    const size_t total_size = 1 << 24; // ~16MB of data to ensure ~0.01s runtime
    tmp = (OPJ_INT32*)aligned_alloc(32, total_size * sizeof(OPJ_INT32));
    
    for (size_t idx = 0; idx < total_size; ++idx) {
        tmp[idx] = (OPJ_INT32)(idx % 1000);
    }

    i = 1; // ensures (i - 1) is 0 and indices stay in bounds
}