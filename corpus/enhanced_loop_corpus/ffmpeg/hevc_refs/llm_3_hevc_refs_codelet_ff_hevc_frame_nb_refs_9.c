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

extern int ret;
extern int i;
extern  ShortTermRPS *rps;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Reverse consecutive memory access
    int start = (int)rps->num_delta_pocs - 1;
    for (; start >= i; start--) {
        ret += !!rps->used[start];
    }
    // Ensure loop index 'i' is updated to reflect completion
    i = rps->num_delta_pocs;
}
