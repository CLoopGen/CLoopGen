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
    ceplen = (1 << 20); // Approximately 4MB of data (1M floats), target 0.01s runtime
    sum = (float32*)calloc(ceplen, sizeof(float32));

    for (i = 0; i < ceplen; i++) {
        sum[i] = (float32)(i % 1000) + 1.0f;
    }

    i = 0; // Reset loop index
}