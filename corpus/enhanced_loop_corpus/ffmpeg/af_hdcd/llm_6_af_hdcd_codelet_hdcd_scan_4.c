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

extern hdcd_state *states;
extern int channels;
extern int i;
extern int cdt_active[2];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_expired[2] = {0};
    for (i = 0; i < channels; i++) {
        if (cdt_active[i] && states[i].sustain == 0) {
            temp_expired[i] = states[i].count_sustain_expired + 1;
        }
    }
    for (i = 0; i < channels; i++) {
        if (cdt_active[i] && states[i].sustain == 0) {
            states[i].count_sustain_expired = temp_expired[i];
        }
    }
}
