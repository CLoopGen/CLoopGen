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
        k = i - 1;
        if (k >= 0) {
            do {
                tmp = rps->delta_poc[k];
                if (!(delta_poc < tmp)) break;
                rps->delta_poc[k + 1] = tmp;
                rps->used[k + 1] = rps->used[k];
                k--;
            } while (k >= 0);
            rps->delta_poc[k + 1] = delta_poc;
            rps->used[k + 1] = used;
        } else {
            rps->delta_poc[0] = delta_poc;
            rps->used[0] = used;
        }
    }
}
