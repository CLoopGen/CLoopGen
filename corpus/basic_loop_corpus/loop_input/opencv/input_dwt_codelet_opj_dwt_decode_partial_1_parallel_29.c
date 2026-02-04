#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef int32_t OPJ_INT32;
typedef uint32_t OPJ_UINT32;

OPJ_INT32 *a;
OPJ_INT32 i;
OPJ_UINT32 off;
OPJ_INT32 i_max;

void init_vars() {
    const size_t total_size = 64 * 1024 * 1024;
    const size_t element_size = sizeof(OPJ_INT32);
    const size_t num_elements = total_size / element_size;

    a = (OPJ_INT32*)aligned_alloc(32, total_size);
    if (!a) exit(1);

    i_max = (num_elements - 8) / (2 * 4);
    if (i_max <= 1) exit(1);

    for (size_t idx = 0; idx < num_elements; ++idx) {
        a[idx] = rand() % 1000;
    }

    i = 1;
    off = 0;
}