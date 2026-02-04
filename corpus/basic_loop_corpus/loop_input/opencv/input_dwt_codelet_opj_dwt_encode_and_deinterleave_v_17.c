#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int32_t OPJ_INT32;
typedef uint32_t OPJ_UINT32;

OPJ_INT32 *restrict tmp;
OPJ_UINT32 c;

void init_vars() {
    tmp = (OPJ_INT32*)aligned_alloc(32, 8 * sizeof(OPJ_INT32));
    for (OPJ_UINT32 i = 0; i < 8; i++) {
        tmp[i] = (OPJ_INT32)(i + 1);
    }
}