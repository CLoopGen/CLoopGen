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

hdcd_state *state;
int i;

void init_vars() {
    state = (hdcd_state*)calloc(1, sizeof(hdcd_state));
    if (!state) {
        exit(1);
    }
    i = 0;
}