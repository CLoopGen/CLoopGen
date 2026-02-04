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

typedef struct TemporalNoiseShaping {
    int present;
    int n_filt[8];
    int length[8][4];
    int direction[8][4];
    int order[8][4];
    int coef_idx[8][4][20];
    INTFLOAT coef[8][4][20];
} TemporalNoiseShaping;

typedef struct Pulse {
    int num_pulse;
    int start;
    int pos[4];
    int amp[4];
} Pulse;

enum BandType {
    ZERO_BT = 0,
    FIRST_PAIR_BT = 5,
    ESC_BT = 11,
    RESERVED_BT = 12,
    NOISE_BT = 13,
    INTENSITY_BT2 = 14,
    INTENSITY_BT = 15
};

typedef float AAC_FLOAT;

typedef struct PredictorState {
    AAC_FLOAT cor0;
    AAC_FLOAT cor1;
    AAC_FLOAT var0;
    AAC_FLOAT var1;
    AAC_FLOAT r0;
    AAC_FLOAT r1;
    AAC_FLOAT k1;
    AAC_FLOAT x_est;
} PredictorState;

typedef struct SingleChannelElement {
    IndividualChannelStream ics;
    TemporalNoiseShaping tns;
    Pulse pulse;
    enum BandType band_type[128];
    enum BandType band_alt[128];
    int band_type_run_end[120];
    INTFLOAT sf[120];
    int sf_idx[128];
    uint8_t zeroes[128];
    uint8_t can_pns[128];
    float is_ener[128];
    float pns_ener[128];
    INTFLOAT pcoeffs[1024] __attribute__((aligned(32)));
    INTFLOAT coeffs[1024] __attribute__((aligned(32)));
    INTFLOAT saved[1536] __attribute__((aligned(32)));
    INTFLOAT ret_buf[2048] __attribute__((aligned(32)));
    INTFLOAT ltp_state[3072] __attribute__((aligned(16)));
    AAC_FLOAT lcoeffs[1024] __attribute__((aligned(32)));
    AAC_FLOAT prcoeffs[1024] __attribute__((aligned(32)));
    PredictorState predictor_state[672];
    INTFLOAT *ret;
} SingleChannelElement;

static uint16_t swb_offset_data[100];
static uint8_t swb_sizes_data[100];

SingleChannelElement *sce;
int i;
int qstep;

void init_vars() {
    sce = (SingleChannelElement*)calloc(1, sizeof(SingleChannelElement));
    if (!sce) exit(1);

    sce->ics.swb_offset = swb_offset_data;
    sce->ics.swb_sizes = swb_sizes_data;
    sce->ics.max_sfb = 40;
    sce->ics.num_window_groups = 1;
    sce->ics.group_len[0] = 1;
    sce->ics.num_swb = 40;
    sce->ics.num_windows = 1;
    sce->ics.tns_max_bands = 40;
    sce->ics.predictor_present = 1;
    sce->ics.predictor_initialized = 1;
    sce->ics.predictor_reset_group = 0;
    for (int j = 0; j < 31; j++) {
        sce->ics.predictor_reset_count[j] = 0;
    }
    for (int j = 0; j < 41; j++) {
        sce->ics.prediction_used[j] = 1;
    }
    sce->ics.clip_avoidance_factor = 1.0f;

    sce->tns.present = 1;
    for (int w = 0; w < 8; w++) {
        sce->tns.n_filt[w] = 1;
        for (int f = 0; f < 4; f++) {
            sce->tns.length[w][f] = 10;
            sce->tns.direction[w][f] = 1;
            sce->tns.order[w][f] = 5;
            for (int k = 0; k < 20; k++) {
                sce->tns.coef_idx[w][f][k] = 0;
                sce->tns.coef[w][f][k] = 0.0f;
            }
        }
    }

    sce->pulse.num_pulse = 0;
    sce->pulse.start = 0;

    for (int j = 0; j < 128; j++) {
        sce->band_type[j] = ZERO_BT;
        sce->band_alt[j] = ZERO_BT;
        sce->sf_idx[j] = 60;
        sce->zeroes[j] = 0;
        sce->can_pns[j] = 1;
        sce->is_ener[j] = 1.0f;
        sce->pns_ener[j] = 1.0f;
    }

    for (int j = 0; j < 120; j++) {
        sce->band_type_run_end[j] = j + 1;
        sce->sf[j] = 1.0f;
    }

    for (int j = 0; j < 1024; j++) {
        sce->pcoeffs[j] = 0.0f;
        sce->coeffs[j] = 0.0f;
        sce->lcoeffs[j] = 0.0f;
        sce->prcoeffs[j] = 0.0f;
    }

    for (int j = 0; j < 1536; j++) {
        sce->saved[j] = 0.0f;
    }

    for (int j = 0; j < 2048; j++) {
        sce->ret_buf[j] = 0.0f;
    }

    for (int j = 0; j < 3072; j++) {
        sce->ltp_state[j] = 0.0f;
    }

    for (int j = 0; j < 672; j++) {
        sce->predictor_state[j].cor0 = 0.0f;
        sce->predictor_state[j].cor1 = 0.0f;
        sce->predictor_state[j].var0 = 1.0f;
        sce->predictor_state[j].var1 = 1.0f;
        sce->predictor_state[j].r0 = 0.0f;
        sce->predictor_state[j].r1 = 0.0f;
        sce->predictor_state[j].k1 = 0.0f;
        sce->predictor_state[j].x_est = 0.0f;
    }

    sce->ret = sce->ret_buf;

    qstep = 5;

    for (int j = 0; j < 100; j++) {
        swb_offset_data[j] = j * 8;
        swb_sizes_data[j] = 8;
    }
}