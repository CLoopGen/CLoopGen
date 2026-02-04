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
    // Variant 1: Increased loop nesting depth by introducing an additional inner loop 
    // that performs a redundant check to simulate more complex nested behavior.
    for (i = 1; i < rps->num_delta_pocs; i++) {
        delta_poc = rps->delta_poc[i];
        used = rps->used[i];
        for (k = i - 1; k >= 0; k--) {
            tmp = rps->delta_poc[k];
            if (delta_poc < tmp) {
                // Additional inner loop simulating fine-grained shift operations
                for (int shift = k + 1; shift <= i; shift++) {
                    rps->delta_poc[shift] = rps->delta_poc[shift - 1];
                    rps->used[shift] = rps->used[shift - 1];
                }
                rps->delta_poc[k] = delta_poc;
                rps->used[k] = used;
                break;
            }
        }
    }
}
