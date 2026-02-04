#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
enum WindowSequence {
    ONLY_LONG_SEQUENCE,
    LONG_START_SEQUENCE,
    EIGHT_SHORT_SEQUENCE,
    LONG_STOP_SEQUENCE
};


typedef float INTFLOAT;

typedef struct LongTermPrediction {
    int8_t present;
    int16_t lag;
    int coef_idx;
    INTFLOAT coef;
    int8_t used[40];
} LongTermPrediction;

typedef struct IndividualChannelStream {
    uint8_t max_sfb;
    enum WindowSequence window_sequence[2];
    uint8_t use_kb_window[2];
    int num_window_groups;
    uint8_t group_len[8];
    LongTermPrediction ltp;
    const uint16_t *swb_offset;
    const uint8_t *swb_sizes;
    int num_swb;
    int num_windows;
    int tns_max_bands;
    int predictor_present;
    int predictor_initialized;
    int predictor_reset_group;
    int predictor_reset_count[31];
    uint8_t prediction_used[41];
    uint8_t window_clipping[8];
    float clip_avoidance_factor;
} IndividualChannelStream;

extern int i;
extern int max_group_id_c;
extern int max_frame;
extern float avg_frame;
extern IndividualChannelStream *ics;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float local_avg = avg_frame;
    int local_max_frame = max_frame;
    int local_max_id = max_group_id_c;

    for (i = 1; i < 31; i += 2) {
        int count_i1 = ics->predictor_reset_count[i];
        int count_i2 = (i + 1 < 31) ? ics->predictor_reset_count[i + 1] : count_i1;

        if (count_i1 > local_max_frame) {
            local_max_frame = count_i1;
            local_max_id = i;
        }
        if (count_i2 > local_max_frame) {
            local_max_frame = count_i2;
            local_max_id = i + 1;
        }

        local_avg = (count_i1 + local_avg) / 2;
        local_avg = (count_i2 + local_avg) / 2;
    }

    max_frame = local_max_frame;
    max_group_id_c = local_max_id;
    avg_frame = local_avg;
}
