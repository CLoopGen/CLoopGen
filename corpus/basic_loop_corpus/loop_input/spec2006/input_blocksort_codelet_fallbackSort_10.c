#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
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
    nblock = 100 * 1024 * 1024; // 100 million elements for ~0.01 sec runtime

    fmap = (UInt32*)malloc(nblock * sizeof(UInt32));
    eclass8 = (UChar*)calloc(nblock, sizeof(UChar));

    for (i = 0; i < nblock; i++) {
        fmap[i] = i; 
    }

    for (i = 0; i < 256; i++) {
        ftabCopy[i] = nblock / 256;
    }
    // Distribute remainder
    for (i = 0; i < nblock % 256; i++) {
        ftabCopy[i]++;
    }

    j = 0;
    while (ftabCopy[j] == 0) j++;
}