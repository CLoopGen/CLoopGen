#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct LongTermRPS {
    int poc[32];
    uint8_t poc_msb_present[32];
    uint8_t used[32];
    uint8_t nb_refs;
} LongTermRPS;

int ret;
int i;
LongTermRPS *long_rps;

void init_vars() {
    long_rps = (LongTermRPS *)calloc(1, sizeof(LongTermRPS));
    if (!long_rps) {
        exit(1);
    }

    long_rps->nb_refs = 32;

    for (int idx = 0; idx < 32; idx++) {
        long_rps->poc[idx] = idx * 10;
        long_rps->poc_msb_present[idx] = idx % 2;
        long_rps->used[idx] = idx % 7 ? 1 : 0;
    }

    ret = 0;
    i = 0;
}