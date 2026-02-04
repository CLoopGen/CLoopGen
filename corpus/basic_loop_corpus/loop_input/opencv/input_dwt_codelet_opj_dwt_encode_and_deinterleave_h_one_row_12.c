#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int32_t OPJ_INT32;

OPJ_INT32 sn;
OPJ_INT32 i;
OPJ_INT32 *restrict row;
OPJ_INT32 *restrict tmp;

void init_vars() {
    sn = 1 << 20; // Approximately 1M elements, adjust for ~0.01s runtime

    // Allocate row to have at least 2*(sn) elements since it's accessed at index (i+1)*2 where i goes up to sn-2
    // So maximum index in row is 2*(sn-1)+1 = 2*sn - 1
    row = (OPJ_INT32*)aligned_alloc(32, sizeof(OPJ_INT32) * (2 * sn));
    
    // tmp needs space for indices up to sn + (sn - 2) = 2*sn - 2, so size 2*sn is safe
    tmp = (OPJ_INT32*)aligned_alloc(32, sizeof(OPJ_INT32) * (2 * sn));

    // Initialize row with dummy data to avoid undefined behavior
    for (OPJ_INT32 idx = 0; idx < 2 * sn; idx++) {
        row[idx] = idx % 256;
    }

    // Initialize tmp partially if needed, though loop only writes to [sn, 2*sn)
    for (OPJ_INT32 idx = 0; idx < sn; idx++) {
        tmp[idx] = 0;
    }
}