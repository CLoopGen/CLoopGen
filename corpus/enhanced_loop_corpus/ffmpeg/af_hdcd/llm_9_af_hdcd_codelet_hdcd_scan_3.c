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
extern int max;
extern int i;
extern int cdt_active[2];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduced effective trip count by unrolling and processing two iterations per loop
    int limit = (channels / 2) * 2;  // Round down to nearest even number
    for (i = 0; i < limit; i += 2) {
        hdcd_state *s1 = &states[i];
        hdcd_state *s2 = &states[i+1];

        // Process first channel
        if (s1->sustain > 0) {
            cdt_active[i] = 1;
            if (s1->sustain <= (unsigned int)max) {
                s1->control = 0;
                max = s1->sustain;
            }
            s1->sustain -= max;
        }

        // Process second channel
        if (s2->sustain > 0) {
            cdt_active[i+1] = 1;
            if (s2->sustain <= (unsigned int)max) {
                s2->control = 0;
                // Use local_max to avoid repeated global max updates
                if (s2->sustain < (unsigned int)max) max = s2->sustain;
            }
            s2->sustain -= max;
        }
    }
    // Handle odd leftover element
    if (channels > limit) {
        hdcd_state *s = &states[limit];
        if (s->sustain > 0) {
            cdt_active[limit] = 1;
            if (s->sustain <= (unsigned int)max) {
                s->control = 0;
                max = s->sustain;
            }
            s->sustain -= max;
        }
    }
}
