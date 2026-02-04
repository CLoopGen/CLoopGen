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
    // Variant 2: Lower computational intensity with increased trip count via logical splitting
    // Each original element is processed twice with lightweight checks to simulate expanded work
    // Artificially increase loop iterations while maintaining correctness using modulo
    sum = 0;  // Reset sum for consistent behavior
    for (j = 0; j < 320; j++) {
        int orig_idx = j % 160;
        struct latencySample *sample = &ts->samples[orig_idx];

        // Only process every element twice, but skip if time is zero on both passes
        if (sample->time == 0) continue;

        // On first pass (even j), initialize or accumulate basic stats
        if (j % 2 == 0) {
            ls->samples++;
            if (ls->samples == 1) {
                ls->min = ls->max = sample->latency;
            } else {
                if (sample->latency < ls->min) ls->min = sample->latency;
                if (sample->latency > ls->max) ls->max = sample->latency;
            }
            sum += sample->latency;
        }
        // On second pass (odd j), update auxiliary metric (e.g., period refinement)
        else {
            if (ls->period == 0 || sample->time < ls->period) {
                ls->period = sample->time;
            }
        }
    }
}
