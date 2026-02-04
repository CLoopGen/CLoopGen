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

extern ShortTermRPS *rps;
extern int delta_poc;
extern int k;
extern int i;
extern int used;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = (rps->num_negative_pics >> 1) - 1;
    for (i = 0; i <= limit; i++) {
        int temp_delta = rps->delta_poc[i];
        uint8_t temp_used = rps->used[i];
        rps->delta_poc[i] = rps->delta_poc[k];
        rps->used[i] = rps->used[k];
        rps->delta_poc[k] = temp_delta;
        rps->used[k] = temp_used;
        k--;
    }
}
