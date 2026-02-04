#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int UInt32;
typedef int Int32;

UInt32 *bhtab;
Int32 ftab[257];
Int32 i;

void init_vars() {
    const size_t bhtab_size = (1 << 20) / sizeof(UInt32); // ~4MB for bhtab
    bhtab = calloc(bhtab_size, sizeof(UInt32));
    if (!bhtab) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < 256; j++) {
        // Ensure ftab[j] generates valid index and bit operations
        // (ftab[j] >> 5) must be within [0, bhtab_size - 1]
        // So ftab[j] must be in [0, (bhtab_size - 1) << 5 + 31]
        ftab[j] = (j * 31) % ((bhtab_size << 5) + 31);
    }
    ftab[256] = 0; // Last element unused in loop, but part of declaration
}