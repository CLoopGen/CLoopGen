#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

struct DssSpSubframe {
    int16_t gain;
    int32_t combined_pulse_pos;
    int16_t pulse_pos[7];
    int16_t pulse_val[7];
};

typedef struct DssSpFrame {
    int16_t filter_idx[14];
    int16_t sf_adaptive_gain[4];
    int16_t pitch_lag[4];
    struct DssSpSubframe sf[4];
} DssSpFrame;

DssSpFrame *fparam;
int i;
uint32_t tmp;
uint32_t pitch_lag;

void init_vars() {
    fparam = (DssSpFrame*)calloc(1, sizeof(DssSpFrame));
    if (!fparam) exit(1);

    for (int j = 0; j < 14; j++) {
        fparam->filter_idx[j] = j % 10;
    }

    for (int j = 0; j < 4; j++) {
        fparam->sf_adaptive_gain[j] = (j + 1) * 512;
        fparam->pitch_lag[j] = 100 + j * 10;
    }

    for (int j = 0; j < 4; j++) {
        fparam->sf[j].gain = j * 100;
        fparam->sf[j].combined_pulse_pos = j * 1000;
        for (int k = 0; k < 7; k++) {
            fparam->sf[j].pulse_pos[k] = k * 5;
            fparam->sf[j].pulse_val[k] = (k % 2) ? 1 : -1;
        }
    }

    i = 0;
    tmp = 0;
    pitch_lag = 180;
}