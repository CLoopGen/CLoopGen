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

static uint16_t swb_offset_data[9] = {0, 4, 8, 12, 16, 20, 24, 28, 32};
static uint8_t swb_sizes_data[8] = {4, 4, 4, 4, 4, 4, 4, 4};

SingleChannelElement *sce;
uint8_t *nextband;
unsigned char prevband;

int w;
int g;

void init_vars() {
    sce = (SingleChannelElement*)aligned_alloc(32, sizeof(SingleChannelElement));
    nextband = (uint8_t*)calloc(256, sizeof(uint8_t));

    sce->ics.num_windows = 8;
    sce->ics.num_swb = 16;
    for (int i = 0; i < 8; ++i) {
        sce->ics.group_len[i] = 1;
    }
    sce->ics.ltp.present = 0;
    sce->ics.swb_offset = swb_offset_data;
    sce->ics.swb_sizes = swb_sizes_data;

    for (int i = 0; i < 128; ++i) {
        sce->zeroes[i] = 0;
        sce->band_type[i] = (i % 16 < 12) ? ZERO_BT : NOISE_BT;
    }

    sce->zeroes[0] = 1;
    sce->zeroes[16] = 1;
    sce->zeroes[32] = 1;
    sce->zeroes[48] = 1;

    prevband = 0;
    for (int i = 0; i < 256; ++i) {
        nextband[i] = 127;
    }

    sce->ret = sce->ret_buf;
}