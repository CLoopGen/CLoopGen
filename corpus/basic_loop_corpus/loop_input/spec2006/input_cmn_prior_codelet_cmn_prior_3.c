#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef int int32;
typedef float float32;

int32 ceplen;
float32 *cur_mean;
float32 *sum;
float32 sf;
int32 i;

void init_vars() {
    ceplen = 65536; 
    sf = 1.5f;

    cur_mean = (float32*)aligned_alloc(32, ceplen * sizeof(float32));
    sum = (float32*)aligned_alloc(32, ceplen * sizeof(float32));

    for (int32 j = 0; j < ceplen; j++) {
        sum[j] = (float32)(j % 1000) + 0.5f;
        cur_mean[j] = 0.0f;
    }
}