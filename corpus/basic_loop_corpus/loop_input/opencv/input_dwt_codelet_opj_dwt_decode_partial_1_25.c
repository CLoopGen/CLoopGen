#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef int32_t OPJ_INT32;

OPJ_INT32 *a;
OPJ_INT32 dn;
OPJ_INT32 win_l_x1;
OPJ_INT32 i;

void init_vars() {
    const size_t data_size_mb = 64;
    const size_t total_elements = (data_size_mb * 1024 * 1024) / sizeof(OPJ_INT32);
    
    a = (OPJ_INT32*)aligned_alloc(32, total_elements * sizeof(OPJ_INT32));
    
    if (!a) {
        fprintf(stderr, "Failed to allocate memory for array 'a'\n");
        exit(EXIT_FAILURE);
    }

    for (size_t idx = 0; idx < total_elements; ++idx) {
        a[idx] = rand() % 1000;
    }

    dn = total_elements / 2;
    win_l_x1 = dn / 2;
    i = 0;
}