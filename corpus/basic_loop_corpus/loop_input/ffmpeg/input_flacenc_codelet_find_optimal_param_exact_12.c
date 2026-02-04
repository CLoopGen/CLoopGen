#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint64_t sums[32][256];
int i = 0;
int max_param = 31;
int bestk = 0;
int64_t bestbits = INT64_MAX;
int k;

void init_vars() {
    for (int idx0 = 0; idx0 < 32; idx0++) {
        for (int idx1 = 0; idx1 < 256; idx1++) {
            sums[idx0][idx1] = rand() % 1000000;
        }
    }
    i = rand() % 256;
    max_param = 31;
    bestbits = INT64_MAX;
    bestk = 0;
}