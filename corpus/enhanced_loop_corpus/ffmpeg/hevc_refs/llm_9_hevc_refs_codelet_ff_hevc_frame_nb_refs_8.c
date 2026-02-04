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



void loop(){
    int step = 2;
    for (i = 0; i < rps->num_negative_pics; i += step) {
        ret += !!rps->used[i];
        if (i + 1 < rps->num_negative_pics) {
            ret += !!rps->used[i + 1];
        }
    }
}
