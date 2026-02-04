#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef uint32_t OPJ_UINT32;
typedef int32_t OPJ_INT32;

OPJ_UINT32 height = 8192;
OPJ_UINT32 stride_width = 8;
OPJ_UINT32 cols = 8;
OPJ_INT32 *restrict array;
OPJ_INT32 *restrict tmp;
OPJ_UINT32 k;

void init_vars() {
    // Allocate arrays with sufficient size to ensure memory safety and performance target
    array = (OPJ_INT32 *restrict)aligned_alloc(32, height * stride_width * sizeof(OPJ_INT32));
    tmp = (OPJ_INT32 *restrict)aligned_alloc(32, height * 8 * sizeof(OPJ_INT32));

    // Initialize array data to non-zero for realistic processing
    for (OPJ_UINT32 i = 0; i < height * stride_width; ++i) {
        array[i] = rand() % 1000;
    }

    // Zero-initialize tmp to ensure clean output before loop
    memset(tmp, 0, height * 8 * sizeof(OPJ_INT32));
}