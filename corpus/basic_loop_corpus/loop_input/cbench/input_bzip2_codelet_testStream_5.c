#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef int Int32;
typedef unsigned char UChar;

Int32 i;
UChar unused[262144]; // 256KB to ensure ~0.01s on modern CPU
Int32 nUnused = 262144;
UChar *unusedTmp;

void init_vars() {
    unusedTmp = (UChar*)malloc(nUnused * sizeof(UChar));
    if (!unusedTmp) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    for (Int32 idx = 0; idx < nUnused; idx++) {
        unusedTmp[idx] = (UChar)(idx & 0xFF);
    }
    i = 0;
}