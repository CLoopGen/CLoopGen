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
    int temp_offsets[3];
    for (i = 1; i < 4; i++) {
        tmp = fparam->pitch_lag[i] - 23;
        if (tmp < 36)
            tmp = 36;
        temp_offsets[i-1] = tmp;
    }
    for (i = 1; i < 4; i++) {
        if (pitch_lag > 162) {
            fparam->pitch_lag[i] += 162 - 23;
        } else {
            fparam->pitch_lag[i] += temp_offsets[i-1];
        }
        pitch_lag = fparam->pitch_lag[i];
    }
}
