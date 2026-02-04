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
    int j;
    for (i = 0, j = rps->num_negative_pics - 1; i < rps->num_negative_pics >> 1; i++, j--) {
        delta_poc = rps->delta_poc[i] + rps->delta_poc[j]; // Introduce RAW: use before potential overwrite
        used = rps->used[i] | rps->used[j];
        rps->delta_poc[i] = rps->delta_poc[j];
        rps->used[i] = rps->used[j];
        rps->delta_poc[j] = delta_poc - rps->delta_poc[j]; // WAW on delta_poc[j], depends on prior write
        rps->used[j] = used & 1;
    }
}
