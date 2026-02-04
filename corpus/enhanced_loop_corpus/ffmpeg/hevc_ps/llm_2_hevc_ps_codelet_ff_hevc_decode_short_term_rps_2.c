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
    // Variant 1: Memory Access Pattern Modification - Strided Access (stride of 2, unrolled pattern)
    // We process elements with a stride to change access pattern, then fix up with a second pass if needed.
    // This variant processes even indices first, then odd, simulating a strided memory access behavior.
    int stride = 2;
    for (int step = 0; step < stride; step++) {
        for (i = 1 + step; i < rps->num_delta_pocs; i += stride) {
            delta_poc = rps->delta_poc[i];
            used = rps->used[i];
            for (k = i - stride; k >= 0; k -= stride) {
                tmp = rps->delta_poc[k];
                if (delta_poc < tmp) {
                    rps->delta_poc[k + stride] = tmp;
                    rps->used[k + stride] = rps->used[k];
                    rps->delta_poc[k] = delta_poc;
                    rps->used[k] = used;
                }
            }
        }
    }
    // Final insertion pass for correctness (handle any gaps due to striding)
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
