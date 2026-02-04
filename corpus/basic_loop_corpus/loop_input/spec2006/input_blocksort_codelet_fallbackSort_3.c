#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef int Int32;
typedef unsigned char UChar;

Int32 nblock = 64 * 1024 * 1024; // 64 million elements for ~0.01 sec runtime
Int32 ftab[257];
Int32 i;
UChar *eclass8;

void init_vars() {
    eclass8 = (UChar *)malloc(nblock * sizeof(UChar));
    if (!eclass8) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize eclass8 with random byte values in range [0, 255]
    srand(time(NULL));
    for (Int32 j = 0; j < nblock; j++) {
        eclass8[j] = (UChar)(rand() % 256);
    }

    // Initialize ftab array to zero
    memset(ftab, 0, 257 * sizeof(Int32));
}