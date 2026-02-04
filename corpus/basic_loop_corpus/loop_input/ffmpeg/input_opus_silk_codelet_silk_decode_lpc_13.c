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

SilkFrame *frame;
int i;
int order = 16;
int16_t nlsf[16];
int offset = 4;
int16_t nlsf_leadin[16];

void init_vars() {
    frame = (SilkFrame *)malloc(sizeof(SilkFrame));
    if (!frame) exit(1);

    for (int j = 0; j < 16; j++) {
        frame->nlsf[j] = (int16_t)(j * 2000);
        nlsf[j] = (int16_t)(j * 2000 + 500);
        nlsf_leadin[j] = 0;
    }

    order = 16;
    offset = 4;
}