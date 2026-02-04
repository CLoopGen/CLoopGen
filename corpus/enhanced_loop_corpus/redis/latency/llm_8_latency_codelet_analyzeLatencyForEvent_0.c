#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct latencyStats {
    uint32_t all_time_high;
    uint32_t avg;
    uint32_t min;
    uint32_t max;
    uint32_t mad;
    uint32_t samples;
    time_t period;
};


struct latencySample {
    int32_t time;
    uint32_t latency;
};


struct latencyTimeSeries {
    int idx;
    uint32_t max;
    struct latencySample samples[160];
};


extern struct latencyStats *ls;
extern struct latencyTimeSeries *ts;
extern int j;
extern uint64_t sum;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Increased computational intensity with trip count reduction and additional arithmetic operations
    // Reduced trip count to 80, but process two elements per iteration (loop unrolling + extra computation)
    // Added computation of squared latency for higher arithmetic intensity
    uint64_t sum_sq = 0;
    for (j = 0; j < 80; j++) {
        int idx1 = j * 2;
        int idx2 = j * 2 + 1;

        // Process first sample
        if (ts->samples[idx1].time != 0) {
            ls->samples++;
            uint32_t lat1 = ts->samples[idx1].latency;
            if (ls->samples == 1 && ls->min == 0 && ls->max == 0) {
                ls->min = ls->max = lat1;
            } else {
                ls->min = (ls->min > lat1) ? lat1 : ls->min;
                ls->max = (ls->max < lat1) ? lat1 : ls->max;
            }
            sum += lat1;
            sum_sq += (uint64_t)lat1 * lat1;
            if (ls->period == 0 || ts->samples[idx1].time < ls->period)
                ls->period = ts->samples[idx1].time;
        }

        // Process second sample
        if (idx2 < 160 && ts->samples[idx2].time != 0) {
            ls->samples++;
            uint32_t lat2 = ts->samples[idx2].latency;
            ls->min = (ls->min > lat2) ? lat2 : ls->min;
            ls->max = (ls->max < lat2) ? lat2 : ls->max;
            sum += lat2;
            sum_sq += (uint64_t)lat2 * lat2;
            if (ls->period == 0 || ts->samples[idx2].time < ls->period)
                ls->period = ts->samples[idx2].time;
        }
    }
    // Dummy use of sum_sq to prevent optimization away
    if (sum_sq > 0) {
        ls->mad = (uint32_t)((sum_sq / ls->samples) % 1000);
    }
}
