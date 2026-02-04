#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct AtracGainInfo {
    int num_points;
    int lev_code[7];
    int loc_code[7];
} AtracGainInfo;

AtracGainInfo *dst;
AtracGainInfo *ref;
int i;

void init_vars() {
    dst = (AtracGainInfo *)aligned_alloc(32, sizeof(AtracGainInfo));
    ref = (AtracGainInfo *)aligned_alloc(32, sizeof(AtracGainInfo));

    dst->num_points = 7;
    ref->num_points = 7;

    for (int j = 0; j < 7; j++) {
        ref->lev_code[j] = (j + 1) * 11;
        ref->loc_code[j] = (j + 1) * 22;
        dst->lev_code[j] = 0;
        dst->loc_code[j] = 0;
    }

    i = 0;
}