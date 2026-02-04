#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct SilkFrame {
    int coded;
    int log_gain;
    int16_t nlsf[16];
    float lpc[16];
    float output[644];
    float lpc_history[644];
    int primarylag;
    int prev_voiced;
} SilkFrame;

extern SilkFrame *frame;
extern int i;
extern int order;
extern int16_t nlsf[16];
extern int offset;
extern int16_t nlsf_leadin[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access (access every second element forward and backward)
    int stride = 2;
    int half_order = (order + stride - 1) / stride;

    // Forward pass: even indices
    for (i = 0; i < order; i += stride) {
        nlsf_leadin[i] = frame->nlsf[i] + ((nlsf[i] - frame->nlsf[i]) * offset >> 2);
    }

    // Backward pass: odd indices if within bounds
    for (i = 1; i < order; i += stride) {
        nlsf_leadin[i] = frame->nlsf[i] + ((nlsf[i] - frame->nlsf[i]) * offset >> 2);
    }
}
