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
    int limit = rps->num_negative_pics > rps->num_delta_pocs ? rps->num_negative_pics : rps->num_delta_pocs;
    for (; i < limit; i++) {
        if (i < rps->num_delta_pocs) {
            ret += (rps->used[i] & 1);
        }
    }
}
