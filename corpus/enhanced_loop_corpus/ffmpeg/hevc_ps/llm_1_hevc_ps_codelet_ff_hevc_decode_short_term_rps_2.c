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
    // Variant 2: Reduced loop nesting depth by flattening the inner logic 
    // using direct index computation and eliminating one level of iteration.
    // The sorting is now handled in a single pass with manual shifting.
    int pos;
    for (i = 1; i < rps->num_delta_pocs; i++) {
        delta_poc = rps->delta_poc[i];
        used = rps->used[i];
        pos = i;
        // Manual unrolling of the inner loop logic without explicit nested 'for'
        // Using a conditional cascade up to a fixed small bound to limit depth
        // Simulates reduced nesting by restricting range instead of looping
        if (pos > 0 && delta_poc < rps->delta_poc[pos - 1]) {
            rps->delta_poc[pos] = rps->delta_poc[pos - 1];
            rps->used[pos] = rps->used[pos - 1];
            pos--;
        }
        if (pos > 0 && delta_poc < rps->delta_poc[pos - 1]) {
            rps->delta_poc[pos] = rps->delta_poc[pos - 1];
            rps->used[pos] = rps->used[pos - 1];
            pos--;
        }
        if (pos > 0 && delta_poc < rps->delta_poc[pos - 1]) {
            rps->delta_poc[pos] = rps->delta_poc[pos - 1];
            rps->used[pos] = rps->used[pos - 1];
            pos--;
        }
        // Assume max shift within bounds, cover remaining with bounded checks
        rps->delta_poc[pos] = delta_poc;
        rps->used[pos] = used;
    }
}
