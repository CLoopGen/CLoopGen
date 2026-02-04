#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int32_t OPJ_INT32;

OPJ_INT32 *restrict row;
OPJ_INT32 *restrict tmp;
OPJ_INT32 sn;
OPJ_INT32 dn;
OPJ_INT32 i;

static OPJ_INT32 *row_storage;
static OPJ_INT32 *tmp_storage;

void init_vars() {
    const size_t total_size = 128 * 1024 * 1024; // 128 MB target data size
    const size_t element_size = sizeof(OPJ_INT32);
    const size_t num_elements = total_size / (3 * element_size); // Distribute across row and tmp

    dn = (OPJ_INT32)(num_elements);
    sn = (OPJ_INT32)(num_elements / 2);

    row_storage = (OPJ_INT32*)aligned_alloc(64, (2 * dn + 2) * element_size);
    tmp_storage = (OPJ_INT32*)aligned_alloc(64, (sn + dn + 2) * element_size);

    if (!row_storage || !tmp_storage) {
        exit(EXIT_FAILURE);
    }

    row = row_storage;
    tmp = tmp_storage;

    for (OPJ_INT32 idx = 0; idx < 2 * dn + 2; idx++) {
        row_storage[idx] = (OPJ_INT32)(idx % 1000);
    }
    for (OPJ_INT32 idx = 0; idx < sn + dn + 2; idx++) {
        tmp_storage[idx] = (OPJ_INT32)((idx + 500) % 1000);
    }
}