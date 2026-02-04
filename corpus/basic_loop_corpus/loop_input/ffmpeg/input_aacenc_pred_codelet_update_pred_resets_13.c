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

int i;
int max_group_id_c;
int max_frame;
float avg_frame;
IndividualChannelStream *ics;

static uint16_t swb_offset_data[50];
static uint8_t swb_sizes_data[50];

void init_vars() {
    ics = (IndividualChannelStream*)calloc(1, sizeof(IndividualChannelStream));
    if (!ics) exit(1);

    ics->max_sfb = 40;
    ics->window_sequence[0] = ONLY_LONG_SEQUENCE;
    ics->window_sequence[1] = LONG_STOP_SEQUENCE;
    ics->use_kb_window[0] = 1;
    ics->use_kb_window[1] = 0;
    ics->num_window_groups = 1;
    for (int j = 0; j < 8; ++j) {
        ics->group_len[j] = 1;
    }
    ics->ltp.present = 1;
    ics->ltp.lag = 1024;
    ics->ltp.coef_idx = 3;
    ics->ltp.coef = 0.85f;
    for (int j = 0; j < 40; ++j) {
        ics->ltp.used[j] = j % 2;
    }
    ics->swb_offset = swb_offset_data;
    ics->swb_sizes = swb_sizes_data;
    for (int j = 0; j < 50; ++j) {
        swb_offset_data[j] = j * 8;
        swb_sizes_data[j] = 8;
    }
    ics->num_swb = 40;
    ics->num_windows = 8;
    ics->tns_max_bands = 20;
    ics->predictor_present = 1;
    ics->predictor_initialized = 1;
    ics->predictor_reset_group = 0;
    for (int j = 0; j < 31; ++j) {
        ics->predictor_reset_count[j] = rand() % 1000;
    }
    for (int j = 0; j < 41; ++j) {
        ics->prediction_used[j] = j % 3;
    }
    for (int j = 0; j < 8; ++j) {
        ics->window_clipping[j] = 0;
    }
    ics->clip_avoidance_factor = 0.95f;

    i = 0;
    max_group_id_c = 0;
    max_frame = 0;
    avg_frame = 0.0f;
}