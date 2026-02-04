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
    for (; i < rps->num_delta_pocs && rps->used[i]; i++)
        ret += 1;
    for (; i < rps->num_delta_pocs; i++)
        if (rps->used[i]) ret += 1;
}
