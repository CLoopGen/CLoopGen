#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct ShortTermRPS {
    unsigned int num_negative_pics;
    int num_delta_pocs;
    int rps_idx_num_delta_pocs;
    int32_t delta_poc[32];
    uint8_t used[32];
} ShortTermRPS;

int ret;
int i;
ShortTermRPS *rps;

void init_vars() {
    rps = (ShortTermRPS*)malloc(sizeof(ShortTermRPS));
    if (!rps) {
        ret = -1;
        return;
    }

    rps->num_negative_pics = 0;
    rps->num_delta_pocs = 32;
    rps->rps_idx_num_delta_pocs = 0;

    for (int idx = 0; idx < 32; ++idx) {
        rps->delta_poc[idx] = idx * 4;
        rps->used[idx] = (uint8_t)(idx % 7 == 0); 
    }

    ret = 0;
    i = 0;
}