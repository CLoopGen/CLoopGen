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
    ls = (struct latencyStats *)calloc(1, sizeof(struct latencyStats));
    ts = (struct latencyTimeSeries *)calloc(1, sizeof(struct latencyTimeSeries));

    ls->samples = 0;
    ls->period = 0;
    sum = 0;

    for (int i = 0; i < 160; i++) {
        ts->samples[i].time = (i % 13) ? (1000 + i * 17) : 0;
        ts->samples[i].latency = 500 + (i * 19) % 1000;
    }
}