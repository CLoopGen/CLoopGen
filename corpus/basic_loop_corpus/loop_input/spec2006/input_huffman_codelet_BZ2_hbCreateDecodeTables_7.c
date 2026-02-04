#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef int Int32;
typedef unsigned char UChar;

Int32 *base;
UChar *length;
Int32 alphaSize;
Int32 i;

void init_vars() {
    alphaSize = 1 << 20; // Approximately 1 million iterations for ~0.01 sec runtime

    length = (UChar*)malloc(alphaSize * sizeof(UChar));
    if (!length) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (Int32 j = 0; j < alphaSize; j++) {
        length[j] = rand() % 255; // Random valid UChar value
    }

    base = (Int32*)calloc(256 + 1, sizeof(Int32)); // Index up to max possible length[i]+1 (255+1)
    if (!base) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}