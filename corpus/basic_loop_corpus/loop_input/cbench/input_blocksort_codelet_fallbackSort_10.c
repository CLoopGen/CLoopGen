#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int UInt32;
typedef int Int32;
typedef unsigned char UChar;

UInt32 *fmap;
Int32 nblock;
Int32 ftabCopy[256];
Int32 i;
Int32 j;
UChar *eclass8;

void init_vars() {
    nblock = 64 * 1024 * 1024; // 64 million blocks to target ~0.01 sec runtime

    fmap = (UInt32*)malloc(nblock * sizeof(UInt32));
    eclass8 = (UChar*)malloc(nblock * sizeof(UChar));

    for (i = 0; i < nblock; i++) {
        fmap[i] = i; 
    }

    for (i = 0; i < 256; i++) {
        ftabCopy[i] = nblock / 256;
    }
    // Adjust last bucket to account for rounding
    ftabCopy[255] += nblock - (nblock / 256) * 256;

    i = 0;
    j = 0;
    // Ensure j starts at first non-zero bucket
    while (j < 256 && ftabCopy[j] == 0) j++;
}