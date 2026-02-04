#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef int Int32;
typedef unsigned char UChar;

Int32 nblock = 67108864; // ~64M elements for ~0.01 sec on modern CPU
Int32 ftab[257];
Int32 i;
UChar *eclass8;

void init_vars() {
    eclass8 = (UChar *)malloc(nblock * sizeof(UChar));
    if (!eclass8) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    for (Int32 j = 0; j < nblock; j++) {
        eclass8[j] = rand() % 256;
    }
    memset(ftab, 0, 257 * sizeof(Int32));
}