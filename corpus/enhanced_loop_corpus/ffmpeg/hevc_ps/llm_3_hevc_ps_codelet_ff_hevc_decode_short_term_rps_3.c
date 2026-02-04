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
    // Variant 2: Strided memory access (stride of 2) with bounds check to maintain correctness
    int limit = (rps->num_negative_pics >> 1);
    int stride = 2;
    int max_idx = (limit + stride - 1) / stride; // Ceiling division to cover all needed iterations
    k = rps->num_delta_pocs - 1; // Re-establishing k if it's expected to start from end (contextual assumption)
    for (i = 0; i < max_idx; i++) {
        int idx = i * stride;
        if (idx >= limit) break;
        delta_poc = rps->delta_poc[idx];
        used = rps->used[idx];
        rps->delta_poc[idx] = rps->delta_poc[k];
        rps->used[idx] = rps->used[k];
        rps->delta_poc[k] = delta_poc;
        rps->used[k] = used;
        k--;
    }
}
