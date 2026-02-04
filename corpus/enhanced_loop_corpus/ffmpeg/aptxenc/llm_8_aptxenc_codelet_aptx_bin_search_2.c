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
    int32_t shift_val = nb_intervals >> 1;
    int64_t scaled_value = (int64_t)value << 24;
    int64_t factor64 = (int64_t)factor;

    for (i = shift_val; i > 0; i >>= 2) { // Reduce trip count by shifting more aggressively
        int32_t offset1 = temp_idx + i;
        int32_t offset2 = temp_idx + (i >> 1);

        if (offset1 < nb_intervals && (factor64 * (int64_t)intervals[offset1]) <= scaled_value)
            temp_idx = offset1;

        if (offset2 < nb_intervals && (factor64 * (int64_t)intervals[offset2]) <= scaled_value)
            temp_idx = offset2;
    }
    idx = temp_idx;
}
