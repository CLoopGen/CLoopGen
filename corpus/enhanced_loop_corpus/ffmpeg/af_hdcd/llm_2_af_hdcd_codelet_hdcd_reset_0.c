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

extern hdcd_state *state;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2, unrolled to handle boundary
    int idx;
    for (idx = 0; idx < 16; idx += 2) {
        state->gain_counts[idx] = 0;
        if (idx + 1 < 16) {
            state->gain_counts[idx + 1] = 0;
        }
    }
}
