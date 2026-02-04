#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

typedef int int32;
typedef float float32;

int32 ceplen;
float32 *sum;
float32 sf;
int32 i;

void init_vars() {
    sf = 1.5f;
    ceplen = (1 << 24) / sizeof(float32);  // ~16.7M elements for ~64 MB of data
    sum = (float32*)aligned_alloc(32, ceplen * sizeof(float32));
    for (int32 idx = 0; idx < ceplen; idx++) {
        sum[idx] = (float32)(idx % 1000) + 1.0f;
    }
    i = 0;
}