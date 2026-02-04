#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef int Int32;
typedef unsigned char UChar;

Int32 *code;
UChar *length;
Int32 minLen;
Int32 maxLen;
Int32 alphaSize;
Int32 n;
Int32 vec;
Int32 i;

void init_vars() {
    alphaSize = 65536; // 64K symbols to ensure sufficient data size
    minLen = 1;
    maxLen = 20;
    vec = 0;

    // Allocate memory for length and code arrays
    length = (UChar*)calloc(alphaSize, sizeof(UChar));
    code = (Int32*)malloc(alphaSize * sizeof(Int32));

    // Initialize length array with values distributed across minLen to maxLen
    for (i = 0; i < alphaSize; i++) {
        length[i] = (UChar)(minLen + (i % (maxLen - minLen + 1)));
    }

    // Initialize code array to zero
    memset(code, 0, alphaSize * sizeof(Int32));
}