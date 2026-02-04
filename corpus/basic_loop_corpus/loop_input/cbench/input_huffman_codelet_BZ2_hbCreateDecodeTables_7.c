#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef int Int32;
typedef unsigned char UChar;

Int32 *base;
UChar *length;
Int32 alphaSize;
Int32 i;

void init_vars() {
    alphaSize = 256 * 1024; 

    length = (UChar *)malloc(alphaSize * sizeof(UChar));
    if (!length) {
        exit(1);
    }

    for (Int32 idx = 0; idx < alphaSize; idx++) {
        length[idx] = (UChar)(idx % 255); 
    }

    base = (Int32 *)calloc(257, sizeof(Int32)); 
    if (!base) {
        free(length);
        exit(1);
    }
}