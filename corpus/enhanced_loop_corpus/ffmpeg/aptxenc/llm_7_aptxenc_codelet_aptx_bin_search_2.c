#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t value;
extern int32_t factor;
extern  int32_t *intervals;
extern int32_t nb_intervals;
extern int32_t idx;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32_t local_idx = idx;
    int32_t step = nb_intervals >> 1;
    for (i = step; i > 0; i >>= 1) {
        int32_t access_idx = local_idx + i;
        int64_t interval_val = (int64_t)(intervals[access_idx]);
        int64_t product = (int64_t)(factor) * interval_val;
        int64_t limit = ((int64_t)value << 24);
        if (product <= limit) {
            local_idx = access_idx;
        } else {
            // Introduce a WAW dependency on local_idx even when not updating from condition,
            // maintaining loop-carried dependence but altering control flow effect
            local_idx = local_idx; // Redundant assignment to create WAW pattern
        }
    }
    idx = local_idx;
}
