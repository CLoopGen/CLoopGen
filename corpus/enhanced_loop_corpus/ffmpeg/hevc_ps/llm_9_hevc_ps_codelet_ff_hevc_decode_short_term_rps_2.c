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
    // Variant 2: Reduced computational complexity by limiting inner loop iterations and simplifying comparisons
    int limit = rps->num_delta_pocs < 16 ? rps->num_delta_pocs : 16; // Cap outer loop to first 16 elements
    for (i = 1; i < limit; i++) {
        delta_poc = rps->delta_poc[i];
        used = rps->used[i];
        // Inner loop runs at most 4 iterations back for reduced complexity
        int start = (i - 4) > 0 ? i - 4 : 0;
        for (k = i - 1; k >= start; k--) {
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
