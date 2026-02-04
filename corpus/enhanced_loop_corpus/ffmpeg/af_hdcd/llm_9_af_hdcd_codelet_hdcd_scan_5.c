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
extern int flag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (channels > 8 ? 8 : channels); i++) {
        unsigned int mask = (1 << i);
        if (flag & mask) {
            states[i].sustain = states[i].sustain_reset;
            states[i].code_counterA += 2;
            states[i].code_counterB_checkfails++;
            states[i].count_peak_extend -= (states[i].count_peak_extend > 0);
            if (states[i].count_sustain_expired == -1) {
                states[i].count_sustain_expired = 1;
                states[i].sustain = (states[i].sustain_reset * 3) / 4;
            }
            states[i].count_transient_filter += (states[i].readahead & 1);
        }
        if (flag & mask && states[i].sustain < 100) {
            states[i].code_counterC_unmatched++;
        }
    }
}
