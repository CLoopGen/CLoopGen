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
for (i = 1; i < rps->num_delta_pocs; i++) {
    delta_poc = rps->delta_poc[i];
    used = rps->used[i];
    for (k = i - 1; k >= 0; k--) {
        tmp = rps->delta_poc[k];
        if (delta_poc < tmp) {
            rps->delta_poc[k + 1] = tmp;
            rps->used[k + 1] = rps->used[k];
            rps->delta_poc[k] = delta_poc;
            rps->used[k] = used;
        }
    }
}

}
