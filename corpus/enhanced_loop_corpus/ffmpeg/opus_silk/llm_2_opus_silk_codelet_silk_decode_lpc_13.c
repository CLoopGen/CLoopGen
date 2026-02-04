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
    // Variant 1: Consecutive memory access with pointer arithmetic
    int16_t *nlsf_lead_ptr = nlsf_leadin;
    int16_t *frame_nlsf_ptr = frame->nlsf;
    int16_t *nlsf_ptr = nlsf;
    for (i = 0; i < order; i++) {
        *nlsf_lead_ptr++ = *frame_nlsf_ptr++ + (((*nlsf_ptr++) - *(frame_nlsf_ptr - 1)) * offset >> 2);
    }
}
