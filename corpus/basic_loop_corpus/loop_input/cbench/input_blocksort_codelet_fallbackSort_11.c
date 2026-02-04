#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef unsigned int UInt32;
typedef int Int32;

UInt32 *fmap;
UInt32 *eclass;
UInt32 *bhtab;
Int32 nblock;
Int32 H;
Int32 i;
Int32 j;
Int32 k;

void init_vars() {
    nblock = 1 << 20; // 1M elements, approx 4MB per array
    H = nblock / 4;
    i = 0;
    j = 0;
    k = 0;

    fmap = (UInt32*)calloc(nblock, sizeof(UInt32));
    eclass = (UInt32*)calloc(nblock, sizeof(UInt32));
    bhtab = (UInt32*)calloc((nblock + 31) / 32, sizeof(UInt32));

    for (Int32 idx = 0; idx < nblock; idx++) {
        fmap[idx] = (UInt32)(idx * 37 % nblock);
    }

    for (Int32 idx = 0; idx < nblock; idx++) {
        if (idx % 17 == 0) {
            bhtab[idx >> 5] |= (1U << (idx & 31));
        }
    }
}