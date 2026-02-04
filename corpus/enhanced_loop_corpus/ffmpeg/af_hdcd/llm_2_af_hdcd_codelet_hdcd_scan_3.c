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
    // Variant 1: Strided memory access with reverse traversal
    for (i = channels - 1; i >= 0; i -= 2) {
        int idx = i; // Logical index, in case of future expansion
        if (states[idx].sustain > 0) {
            cdt_active[idx] = 1;
            if (states[idx].sustain <= (unsigned int)max) {
                states[idx].control = 0;
                max = states[idx].sustain;
            }
            states[idx].sustain -= max;
        }
        // Handle strided access: process every second element
        if (i == 0) break; // Prevent underflow when subtracting stride
        int prev_idx = i - 1;
        if (states[prev_idx].sustain > 0) {
            cdt_active[prev_idx] = 1;
            if (states[prev_idx].sustain <= (unsigned int)max) {
                states[prev_idx].control = 0;
                max = states[prev_idx].sustain;
            }
            states[prev_idx].sustain -= max;
        }
    }
}
