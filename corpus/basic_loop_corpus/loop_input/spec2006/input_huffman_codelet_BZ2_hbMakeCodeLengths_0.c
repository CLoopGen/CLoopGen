#include <stdio.h>
#include <inttypes.h>

typedef int Int32;

Int32 alphaSize = 512;
Int32 i;
Int32 *freq;
Int32 weight[516];

void init_vars() {
    freq = (Int32*)__builtin_malloc(alphaSize * sizeof(Int32));
    for (i = 0; i < alphaSize; i++) {
        freq[i] = i & 0xFF;
        weight[i + 1] = 0;
    }
    weight[0] = 0;
    if (alphaSize > 0) {
        weight[alphaSize] = 0;
    }
}