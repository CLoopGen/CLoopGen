#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef int Int32;
typedef unsigned char UChar;

Int32 *perm;
UChar *length;
Int32 minLen = 1;
Int32 maxLen = 20;
Int32 alphaSize = 256;
Int32 pp = 0;
Int32 i;
Int32 j;

void init_vars() {
    const size_t perm_size = 1 << 24; // 16M elements, ~64 MB
    perm = (Int32*)malloc(perm_size * sizeof(Int32));
    if (!perm) {
        fprintf(stderr, "Failed to allocate perm\n");
        exit(1);
    }

    length = (UChar*)malloc(alphaSize * sizeof(UChar));
    if (!length) {
        fprintf(stderr, "Failed to allocate length\n");
        exit(1);
    }

    srand((unsigned int)time(NULL));

    for (i = 0; i < alphaSize; i++) {
        length[i] = (UChar)(minLen + rand() % (maxLen - minLen + 1));
    }

    pp = 0;
}