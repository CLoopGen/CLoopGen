#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct VolDetectContext {
    uint64_t histogram[65537];
} VolDetectContext;

extern VolDetectContext *vd;
extern int i;
extern int shift;
extern uint64_t power;
extern uint64_t nb_samples_shift;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with increased per-iteration work via expanded inner logic and conditional accumulation
    // Simulate higher-level aggregation by grouping indices and applying weight scaling
    int step = 8;
    uint64_t temp_power = 0;
    uint64_t temp_samples = 0;

    for (i = 0; i < 65536; i += step) {
        uint64_t block_sum = 0;
        uint64_t weighted_sum = 0;

        // Process a block of 8 elements
        for (int j = 0; j < step && (i + j) < 65536; j++) {
            uint64_t h = vd->histogram[i + j] >> shift;
            block_sum += h;
            int64_t diff = (i + j) - 32768;
            weighted_sum += diff * diff * h;

            // Extra computation: simulate variance correction term
            if (h > 0) {
                weighted_sum += (diff * h) >> 4;  // Small linear adjustment
            }
        }

        temp_samples += block_sum;
        temp_power += weighted_sum;

        // Additional overhead: artificial dependency to increase compute pressure
        if (block_sum > 1000) {
            temp_power += (block_sum * block_sum) >> 10;
        }
    }

    nb_samples_shift += temp_samples;
    power += temp_power;
}
