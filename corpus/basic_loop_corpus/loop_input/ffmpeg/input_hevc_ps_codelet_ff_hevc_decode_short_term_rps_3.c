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

ShortTermRPS *rps;
int delta_poc;
int k;
int i;
int used;

void init_vars() {
    rps = (ShortTermRPS*)calloc(1, sizeof(ShortTermRPS));
    if (!rps) exit(1);

    rps->num_negative_pics = 30;
    rps->num_delta_pocs = 32;
    rps->rps_idx_num_delta_pocs = 32;

    for (int idx = 0; idx < 32; idx++) {
        rps->delta_poc[idx] = (int32_t)(idx * 5);
        rps->used[idx] = (uint8_t)((idx % 3) + 1);
    }

    k = rps->num_negative_pics - 1;
    i = 0;
    delta_poc = 0;
    used = 0;
}