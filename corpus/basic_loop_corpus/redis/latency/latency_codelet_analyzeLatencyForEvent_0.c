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
for (j = 0; j < 160; j++) {
    if (ts->samples[j].time == 0)
        continue;
    ls->samples++;
    if (ls->samples == 1) {
        ls->min = ls->max = ts->samples[j].latency;
    } else {
        if (ls->min > ts->samples[j].latency)
            ls->min = ts->samples[j].latency;
        if (ls->max < ts->samples[j].latency)
            ls->max = ts->samples[j].latency;
    }
    sum += ts->samples[j].latency;
    if (ls->period == 0 || ts->samples[j].time < ls->period)
        ls->period = ts->samples[j].time;
}

}
