#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
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

extern DssSpFrame *fparam;
extern int i;
extern uint32_t tmp;
extern uint32_t pitch_lag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Decreased effective depth by unrolling the original loop body for each value of i
    i = 1;
    if (pitch_lag > 162) {
        fparam->pitch_lag[i] += 162 - 23;
    } else {
        tmp = pitch_lag - 23;
        if (tmp < 36)
            tmp = 36;
        fparam->pitch_lag[i] += tmp;
    }
    pitch_lag = fparam->pitch_lag[i];

    i = 2;
    if (pitch_lag > 162) {
        fparam->pitch_lag[i] += 162 - 23;
    } else {
        tmp = pitch_lag - 23;
        if (tmp < 36)
            tmp = 36;
        fparam->pitch_lag[i] += tmp;
    }
    pitch_lag = fparam->pitch_lag[i];

    i = 3;
    if (pitch_lag > 162) {
        fparam->pitch_lag[i] += 162 - 23;
    } else {
        tmp = pitch_lag - 23;
        if (tmp < 36)
            tmp = 36;
        fparam->pitch_lag[i] += tmp;
    }
    pitch_lag = fparam->pitch_lag[i];
}
