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
    for (i = 0; i < channels; i++) {
        hdcd_state *s = &states[i];
        if (cdt_active[i]) {
            s->count_sustain_expired += (s->sustain == 0);
            s->gain_counts[s->running_gain & 0xF]++;
            s->code_counterA_almost += (s->code_counterA > s->code_counterB) ? 1 : 0;
            s->count_peak_extend += (s->control & 0x8) ? 2 : 0;
            s->rate += s->arg * s->arg;
            s->_ana_snb -= (s->_ana_snb >> 4);
        }
    }
}
