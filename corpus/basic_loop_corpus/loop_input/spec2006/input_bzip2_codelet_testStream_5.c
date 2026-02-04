#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef int Int32;
typedef unsigned char UChar;

Int32 i;
UChar unused[5000];
Int32 nUnused = 5000;
UChar *unusedTmp;

void init_vars() {
    unusedTmp = (UChar*)malloc(nUnused * sizeof(UChar));
    for (Int32 idx = 0; idx < nUnused; idx++) {
        unused[idx] = 0;
        unusedTmp[idx] = (UChar)(idx & 0xFF);
    }
}