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

extern int ret;
extern int i;
extern  ShortTermRPS *rps;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int local_ret = ret;
    for (i = 0; i < rps->num_negative_pics; i++) {
        local_ret += (rps->used[i] != 0);
        rps->delta_poc[i] = rps->delta_poc[i]; // WAW dependency on delta_poc (redundant write, no semantic change)
    }
    ret = local_ret;
}
