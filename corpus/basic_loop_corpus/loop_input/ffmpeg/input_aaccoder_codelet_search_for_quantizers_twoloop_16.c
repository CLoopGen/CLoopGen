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
typedef float AAC_FLOAT;

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

const uint16_t *swb_offset_ptr = swb_offset_data;
const uint8_t *swb_sizes_ptr = swb_sizes_data;

SingleChannelElement *sce;
int i;
int maxsf[128];
int tbits;
int qstep;
int changed;

void init_vars() {
    sce = (SingleChannelElement*)aligned_alloc(32, sizeof(SingleChannelElement));
    if (!sce) exit(1);

    for (int i = 0; i < 128; i++) {
        sce->sf_idx[i] = i * 2;
        maxsf[i] = 200 + (i % 56);
    }

    sce->ics.swb_offset = swb_offset_ptr;
    sce->ics.swb_sizes = swb_sizes_ptr;
    sce->ics.max_sfb = 40;
    sce->ics.num_window_groups = 1;
    sce->ics.group_len[0] = 1;
    sce->ics.ltp.present = 0;
    sce->ics.predictor_present = 1;
    sce->ics.predictor_initialized = 1;
    sce->ics.predictor_reset_group = 0;
    sce->ics.num_swb = 40;
    sce->ics.num_windows = 1;
    sce->ics.tns_max_bands = 20;
    sce->ics.clip_avoidance_factor = 1.0f;

    sce->tns.present = 0;

    sce->pulse.num_pulse = 0;

    for (int i = 0; i < 128; i++) {
        sce->band_type[i] = ZERO_BT;
        sce->band_alt[i] = ZERO_BT;
        sce->zeroes[i] = 1;
        sce->can_pns[i] = 1;
        sce->is_ener[i] = 1.0f;
        sce->pns_ener[i] = 1.0f;
    }

    for (int i = 0; i < 120; i++) {
        sce->band_type_run_end[i] = i * 2;
        sce->sf[i] = 1.0f;
    }

    for (int i = 0; i < 1024; i++) {
        sce->pcoeffs[i] = 0.0f;
        sce->coeffs[i] = 0.0f;
        sce->lcoeffs[i] = 0.0f;
        sce->prcoeffs[i] = 0.0f;
    }

    for (int i = 0; i < 1536; i++) {
        sce->saved[i] = 0.0f;
    }

    for (int i = 0; i < 2048; i++) {
        sce->ret_buf[i] = 0.0f;
    }

    for (int i = 0; i < 3072; i++) {
        sce->ltp_state[i] = 0.0f;
    }

    for (int i = 0; i < 672; i++) {
        sce->predictor_state[i].cor0 = 0.0f;
        sce->predictor_state[i].cor1 = 0.0f;
        sce->predictor_state[i].var0 = 1.0f;
        sce->predictor_state[i].var1 = 1.0f;
        sce->predictor_state[i].r0 = 0.0f;
        sce->predictor_state[i].r1 = 0.0f;
        sce->predictor_state[i].k1 = 0.0f;
        sce->predictor_state[i].x_est = 0.0f;
    }

    sce->ret = sce->ret_buf;

    tbits = 6000;
    qstep = 10;
    changed = 0;

    for (int i = 0; i < 128; i++) {
        swb_offset_data[i] = i * 8;
        swb_sizes_data[i] = 8;
    }
}