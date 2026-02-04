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
    for (j = 0; j < 160; j++) {
        int time_nonzero = (ts->samples[j].time != 0);
        ls->samples += time_nonzero;
        if (time_nonzero) {
            uint32_t lat = ts->samples[j].latency;
            if (ls->samples == 1) {
                ls->min = ls->max = lat;
                ls->period = ts->samples[j].time;
            } else {
                ls->min = (lat < ls->min) ? lat : ls->min;
                ls->max = (lat > ls->max) ? lat : ls->max;
                if (ts->samples[j].time < ls->period) {
                    ls->period = ts->samples[j].time;
                }
            }
            sum += lat;
        }
    }
}
