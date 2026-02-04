#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int UInt32;
typedef int Int32;
typedef unsigned char UChar;

UInt32 *fmap;
Int32 nblock;
Int32 ftab[257];
Int32 i;
Int32 j;
Int32 k;
UChar *eclass8;

void init_vars() {
    nblock = 64 * 1024 * 1024;  // ~64 million elements for ~0.01 sec runtime

    fmap = (UInt32*)calloc(nblock, sizeof(UInt32));
    eclass8 = (UChar*)malloc(nblock * sizeof(UChar));

    if (!fmap || !eclass8) {
        exit(1);
    }

    for (Int32 idx = 0; idx < nblock; idx++) {
        eclass8[idx] = (UChar)(idx % 256);
    }

    memset(ftab, 0, 257 * sizeof(Int32));

    for (Int32 idx = 0; idx < nblock; idx++) {
        ftab[eclass8[idx]]++;
    }

    Int32 sum = 0;
    for (Int32 idx = 0; idx < 257; idx++) {
        Int32 count = ftab[idx];
        ftab[idx] = sum;
        sum += count;
    }
}