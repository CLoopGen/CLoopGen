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



void loop(){
    int64_t delta;
    for (j = 0; j < 160; j++) {
        if (ts->samples[j].time != 0) {
            delta = (int64_t)ls->avg - ts->samples[j].latency;
            if (delta < 0)
                delta = -delta;
            sum += delta;
        }
    }
}
