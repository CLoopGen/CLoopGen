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
extern int tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_delta, temp_used;
    for (i = 1; i < rps->num_delta_pocs; i++) {
        temp_delta = rps->delta_poc[i];
        temp_used = rps->used[i];
        k = i - 1;
        while (k >= 0 && rps->delta_poc[k] > temp_delta) {
            rps->delta_poc[k + 1] = rps->delta_poc[k];
            rps->used[k + 1] = rps->used[k];
            k--;
        }
        rps->delta_poc[k + 1] = temp_delta;
        rps->used[k + 1] = temp_used;
    }
}
