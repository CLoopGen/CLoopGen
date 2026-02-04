#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
    alphaSize = 1 << 18; // ~262,144 elements to ensure sufficient workload
    minLen = 1;
    maxLen = 20;
    vec = 0;

    length = (UChar*)calloc(alphaSize, sizeof(UChar));
    code = (Int32*)malloc(alphaSize * sizeof(Int32));

    if (!length || !code) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    srand(time(NULL));
    for (Int32 idx = 0; idx < alphaSize; idx++) {
        length[idx] = (UChar)(minLen + rand() % (maxLen - minLen + 1));
    }

    for (Int32 idx = 0; idx < alphaSize; idx++) {
        code[idx] = -1;
    }
}