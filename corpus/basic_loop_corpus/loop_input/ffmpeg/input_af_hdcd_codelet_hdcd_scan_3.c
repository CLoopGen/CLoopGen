#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct hdcd_state {
    uint64_t window;
    unsigned char readahead;
    uint8_t arg;
    uint8_t control;
    unsigned int sustain;
    unsigned int sustain_reset;
    int running_gain;
    int code_counterA;
    int code_counterA_almost;
    int code_counterB;
    int code_counterB_checkfails;
    int code_counterC;
    int code_counterC_unmatched;
    int count_peak_extend;
    int count_transient_filter;
    int gain_counts[16];
    int max_gain;
    int count_sustain_expired;
    int rate;
    int _ana_snb;
} hdcd_state;

hdcd_state *states;
int channels;
int max;
int i;
int cdt_active[2];

void init_vars() {
    channels = 2;
    max = 50000;

    states = (hdcd_state*)calloc(channels, sizeof(hdcd_state));
    if (!states) {
        exit(1);
    }

    for (int idx = 0; idx < channels; idx++) {
        states[idx].sustain = 100000 + idx * 20000;
        states[idx].sustain_reset = 0;
        states[idx].control = 1;
        states[idx].running_gain = 0;
        states[idx].code_counterA = 0;
        states[idx].code_counterA_almost = 0;
        states[idx].code_counterB = 0;
        states[idx].code_counterB_checkfails = 0;
        states[idx].code_counterC = 0;
        states[idx].code_counterC_unmatched = 0;
        states[idx].count_peak_extend = 0;
        states[idx].count_transient_filter = 0;
        for (int j = 0; j < 16; j++) {
            states[idx].gain_counts[j] = 0;
        }
        states[idx].max_gain = 0;
        states[idx].count_sustain_expired = 0;
        states[idx].rate = 0;
        states[idx].window = 0;
        states[idx].readahead = 0;
        states[idx].arg = 0;
        states[idx]._ana_snb = 0;
    }

    cdt_active[0] = 0;
    cdt_active[1] = 0;
}