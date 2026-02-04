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
    int32_t temp_idx = idx;
    for (i = nb_intervals >> 1; i > 0; i >>= 1) {
        int64_t scaled_factor = (int64_t)(factor) * (int64_t)(intervals[temp_idx + i]);
        int64_t threshold = (int64_t)value << 24;
        if (scaled_factor <= threshold)
            temp_idx += i;
    }
    idx = temp_idx;
}
