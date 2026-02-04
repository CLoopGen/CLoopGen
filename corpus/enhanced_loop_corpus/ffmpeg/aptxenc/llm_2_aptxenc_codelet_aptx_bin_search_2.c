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
    // Variant 1: Strided memory access with increasing stride
    int stride = 1;
    for (i = nb_intervals >> 1; i > 0; i >>= 1) {
        stride *= 2; // Increasing stride pattern
        int access_idx = idx + (i * stride);
        if (access_idx < nb_intervals && 
            ((int64_t)(factor) * (int64_t)(intervals[access_idx])) <= ((int64_t)value << 24))
            idx += i;
    }
}
