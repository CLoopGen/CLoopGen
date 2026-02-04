#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

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

struct latencyStats *ls;
struct latencyTimeSeries *ts;
int j;
uint64_t sum;

void init_vars() {
    // Allocate and initialize latencyStats
    ls = (struct latencyStats *)calloc(1, sizeof(struct latencyStats));
    if (!ls) exit(1);
    ls->avg = 5000;

    // Allocate and initialize latencyTimeSeries
    ts = (struct latencyTimeSeries *)calloc(1, sizeof(struct latencyTimeSeries));
    if (!ts) exit(1);
    ts->max = 160;
    ts->idx = 0;

    // Initialize samples: fill with valid data, some zero-time entries to trigger continue
    for (int i = 0; i < 160; i++) {
        if (i % 16 == 0) {
            ts->samples[i].time = 0; // Every 16th entry has time=0 to test 'continue'
            ts->samples[i].latency = 0;
        } else {
            ts->samples[i].time = i * 100 + 1;
            ts->samples[i].latency = 4000 + (i % 2000); // latency around 4000-5999
        }
    }

    // Initialize loop counter and accumulator
    j = 0;
    sum = 0;
}