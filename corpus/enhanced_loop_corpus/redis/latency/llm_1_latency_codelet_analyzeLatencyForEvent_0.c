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
    for (j = 0; j < 16; j++) {
        for (int k = 0; k < 10; k++) {
            int index = j * 10 + k;
            if (index >= 160) break;
            if (ts->samples[index].time == 0)
                continue;
            ls->samples++;
            if (ls->samples == 1) {
                ls->min = ls->max = ts->samples[index].latency;
            } else {
                if (ls->min > ts->samples[index].latency)
                    ls->min = ts->samples[index].latency;
                if (ls->max < ts->samples[index].latency)
                    ls->max = ts->samples[index].latency;
            }
            sum += ts->samples[index].latency;
            if (ls->period == 0 || ts->samples[index].time < ls->period)
                ls->period = ts->samples[index].time;
        }
    }
}
