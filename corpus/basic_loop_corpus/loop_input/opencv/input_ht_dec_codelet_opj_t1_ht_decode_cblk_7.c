#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int32_t OPJ_INT32;
typedef uint32_t OPJ_UINT32;

OPJ_INT32 width;
OPJ_UINT32 *sig;
OPJ_UINT32 *mbr;
OPJ_UINT32 prev;
OPJ_INT32 i;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~256 MB of total data (each array)
    sig = (OPJ_UINT32*)aligned_alloc(32, data_size);
    mbr = (OPJ_UINT32*)aligned_alloc(32, data_size);

    if (!sig || !mbr) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t j = 0; j < data_size / sizeof(OPJ_UINT32); ++j) {
        sig[j] = (OPJ_UINT32)(j * 7890123U);
        mbr[j] = 0U;
    }

    width = (data_size / sizeof(OPJ_UINT32)) - 7; // Ensure sig[i+1] and mbr[i+7] accesses are valid when i += 8
    prev = 0x12345678U;
}