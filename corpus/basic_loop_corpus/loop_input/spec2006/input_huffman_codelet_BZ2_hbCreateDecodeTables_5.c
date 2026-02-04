#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef int Int32;
typedef unsigned char UChar;

Int32 *perm;
UChar *length;
Int32 minLen = 1;
Int32 maxLen = 16;
Int32 alphaSize = 256 * 1024; // 256KB of input data
Int32 pp = 0;
Int32 i = 0;
Int32 j = 0;

void init_vars() {
    perm = (Int32*)malloc(alphaSize * sizeof(Int32));
    length = (UChar*)malloc(alphaSize * sizeof(UChar));

    for (Int32 idx = 0; idx < alphaSize; idx++) {
        length[idx] = (UChar)(1 + (idx % 16));
        perm[idx] = 0;
    }
}