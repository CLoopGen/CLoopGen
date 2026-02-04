#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct AtracGainInfo {
    int num_points;
    int lev_code[7];
    int loc_code[7];
} AtracGainInfo;

int b;
AtracGainInfo *gain;

void init_vars() {
    b = 0;
    gain = (AtracGainInfo*)calloc(4, sizeof(AtracGainInfo));
    if (!gain) {
        exit(1);
    }
}