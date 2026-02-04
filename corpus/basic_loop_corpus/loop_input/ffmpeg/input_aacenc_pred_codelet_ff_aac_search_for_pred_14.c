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

static uint16_t swb_offset_data[128];
static uint8_t swb_sizes_data[128];

SingleChannelElement *sce;
int i;

void init_vars() {
    sce = (SingleChannelElement*)calloc(1, sizeof(SingleChannelElement));
    if (!sce) exit(1);

    sce->ics.max_sfb = 0;
    sce->ics.window_sequence[0] = ONLY_LONG_SEQUENCE;
    sce->ics.window_sequence[1] = ONLY_LONG_SEQUENCE;
    sce->ics.use_kb_window[0] = 0;
    sce->ics.use_kb_window[1] = 0;
    sce->ics.num_window_groups = 1;
    sce->ics.group_len[0] = 1;
    sce->ics.ltp.present = 0;
    sce->ics.ltp.lag = 0;
    sce->ics.ltp.coef_idx = 0;
    sce->ics.ltp.coef = 0.0f;
    for (int j = 0; j < 40; j++) sce->ics.ltp.used[j] = 0;

    sce->ics.swb_offset = swb_offset_data;
    sce->ics.swb_sizes = swb_sizes_data;
    sce->ics.num_swb = 1;
    sce->ics.num_windows = 1;
    sce->ics.tns_max_bands = 0;
    sce->ics.predictor_present = 1;
    sce->ics.predictor_initialized = 1;
    sce->ics.predictor_reset_group = 0;
    for (int j = 0; j < 31; j++) sce->ics.predictor_reset_count[j] = 0;
    for (int j = 0; j < 41; j++) sce->ics.prediction_used[j] = 0;
    for (int j = 0; j < 8; j++) sce->ics.window_clipping[j] = 0;
    sce->ics.clip_avoidance_factor = 1.0f;

    sce->tns.present = 0;
    for (int j = 0; j < 8; j++) {
        sce->tns.n_filt[j] = 0;
        for (int k = 0; k < 4; k++) {
            sce->tns.length[j][k] = 0;
            sce->tns.direction[j][k] = 0;
            sce->tns.order[j][k] = 0;
            for (int m = 0; m < 20; m++) {
                sce->tns.coef_idx[j][k][m] = 0;
                sce->tns.coef[j][k][m] = 0.0f;
            }
        }
    }

    sce->pulse.num_pulse = 0;
    sce->pulse.start = 0;
    for (int j = 0; j < 4; j++) {
        sce->pulse.pos[j] = 0;
        sce->pulse.amp[j] = 0;
    }

    for (int j = 0; j < 128; j++) {
        sce->band_type[j] = ZERO_BT;
        sce->band_alt[j] = ZERO_BT;
        sce->sf_idx[j] = 0;
        sce->zeroes[j] = 1;
        sce->can_pns[j] = 0;
        sce->is_ener[j] = 1.0f;
        sce->pns_ener[j] = 1.0f;
    }

    for (int j = 0; j < 120; j++) {
        sce->band_type_run_end[j] = 0;
        sce->sf[j] = 0.0f;
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
        sce->predictor_state[j].var0 = 0.0f;
        sce->predictor_state[j].var1 = 0.0f;
        sce->predictor_state[j].r0 = 0.0f;
        sce->predictor_state[j].r1 = 0.0f;
        sce->predictor_state[j].k1 = 0.0f;
        sce->predictor_state[j].x_est = 0.0f;
    }

    sce->ret = sce->ret_buf;

    i = 0;
}