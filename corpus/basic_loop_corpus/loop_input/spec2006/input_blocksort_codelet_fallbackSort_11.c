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
    nblock = 65536 * 4; 
    H = nblock / 2;
    fmap = (UInt32*)malloc(nblock * sizeof(UInt32));
    eclass = (UInt32*)malloc(nblock * sizeof(UInt32));
    bhtab = (UInt32*)malloc((nblock + 31) / 32 * sizeof(UInt32));

    for (Int32 idx = 0; idx < nblock; ++idx) {
        fmap[idx] = idx;
        eclass[idx] = 0;
    }

    for (Int32 idx = 0; idx < (nblock + 31) / 32; ++idx) {
        bhtab[idx] = 0xFFFFFFFF;
    }

    i = 0;
    j = 0;
    k = 0;
}