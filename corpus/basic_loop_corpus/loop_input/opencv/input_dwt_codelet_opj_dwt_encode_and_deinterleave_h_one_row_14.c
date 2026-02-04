#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int32_t OPJ_INT32;

OPJ_INT32 *restrict row;
OPJ_INT32 *restrict tmp;
OPJ_INT32 sn;
OPJ_INT32 i;

void init_vars() {
    sn = 65536; // Choose size so that loop runs ~0.01s; adjust based on typical CPU speed

    // Allocate row: need up to index 2*(sn-1)+1 = 2*sn - 1
    row = (OPJ_INT32*)aligned_alloc(32, sizeof(OPJ_INT32) * (2 * sn));
    
    // Allocate tmp: need up to index sn + sn = 2*sn
    tmp = (OPJ_INT32*)aligned_alloc(32, sizeof(OPJ_INT32) * (2 * sn + 1));

    // Initialize row with dummy data to prevent undefined behavior
    for (OPJ_INT32 idx = 0; idx < 2 * sn; idx++) {
        row[idx] = idx * 3;
    }

    // Initialize tmp to zero or predictable values
    for (OPJ_INT32 idx = 0; idx < 2 * sn + 1; idx++) {
        tmp[idx] = 0;
    }
}