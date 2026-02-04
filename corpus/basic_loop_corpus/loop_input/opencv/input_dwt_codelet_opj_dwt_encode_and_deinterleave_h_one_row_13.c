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

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~256 MB of total data (adjustable)
    dn = data_size / sizeof(OPJ_INT32) / 3;   // Ensure safe indexing: 2*i < size
    sn = dn;
    
    // Allocate row and tmp with sufficient size
    row = (OPJ_INT32*)aligned_alloc(32, sizeof(OPJ_INT32) * (2 * dn + 1));
    tmp = (OPJ_INT32*)aligned_alloc(32, sizeof(OPJ_INT32) * (sn + dn + 1));

    // Initialize arrays to avoid undefined behavior
    for (OPJ_INT32 idx = 0; idx < 2 * dn + 1; ++idx) {
        row[idx] = idx % 0xFF;
    }
    for (OPJ_INT32 idx = 0; idx < sn + dn + 1; ++idx) {
        tmp[idx] = idx % 0xFF;
    }

    i = 0; // Will be set by loop
}