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
for (i = 0; i < rps->num_negative_pics >> 1; i++) {
    delta_poc = rps->delta_poc[i];
    used = rps->used[i];
    rps->delta_poc[i] = rps->delta_poc[k];
    rps->used[i] = rps->used[k];
    rps->delta_poc[k] = delta_poc;
    rps->used[k] = used;
    k--;
}

}
