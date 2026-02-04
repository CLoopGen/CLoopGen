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
    const size_t total_size = 1 << 20; // ~1MB of data (adjustable)
    tmp = (OPJ_INT32*)calloc(total_size, sizeof(OPJ_INT32));
    if (!tmp) {
        exit(1);
    }
    i = 1; // ensures indices ((1 + i)*2)*8 + c and (i)*2*8 + c are valid for c in [0,7]
}

// Ensure the loop accesses within bounds:
// Accesses: tmp[(i)*2*8 + c] and tmp[((1+i)*2)*8 + c] for c from 0 to 7
// With i = 1: base index = 1*2*8 = 16, second index = (2*2)*8 = 32 -> max index = 32+7 = 39
// So we need at least 40 elements -> our 1MB (>250k elements) is safe