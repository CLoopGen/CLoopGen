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
    const size_t bhtab_size = (1 << 20) / sizeof(UInt32); // ~4MB total, enough for 0.01s runtime
    bhtab = (UInt32*)calloc(bhtab_size, sizeof(UInt32));
    if (!bhtab) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < 256; j++) {
        ftab[j] = rand() % (bhtab_size * 32); // ensure index fits: >>5 gives bhtab index, &31 gives bit position
    }
    ftab[256] = 0; // unused in loop, just initialize
}