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

extern SingleChannelElement *sce;
extern int i;
extern int minsf[128];
extern int qstep;
extern int changed;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    int threshold = 140;
    int local_changed = 0;
    int8_t *used = sce->ics.ltp.used;
    for (i = 0; i < 128; i += 4) {
        int sf0 = sce->sf_idx[i];
        int sf1 = sce->sf_idx[i+1];
        int sf2 = sce->sf_idx[i+2];
        int sf3 = sce->sf_idx[i+3];

        int cond0 = (sf0 > threshold);
        int cond1 = (sf1 > threshold);
        int cond2 = (sf2 > threshold);
        int cond3 = (sf3 > threshold);

        int min0 = (minsf[i] > threshold) ? minsf[i] : threshold;
        int min1 = (minsf[i+1] > threshold) ? minsf[i+1] : threshold;
        int min2 = (minsf[i+2] > threshold) ? minsf[i+2] : threshold;
        int min3 = (minsf[i+3] > threshold) ? minsf[i+3] : threshold;

        int new_sf0 = (min0 > sf0 - qstep) ? min0 : (sf0 - qstep);
        int new_sf1 = (min1 > sf1 - qstep) ? min1 : (sf1 - qstep);
        int new_sf2 = (min2 > sf2 - qstep) ? min2 : (sf2 - qstep);
        int new_sf3 = (min3 > sf3 - qstep) ? min3 : (sf3 - qstep);

        if (cond0 && new_sf0 != sf0) {
            sce->sf_idx[i] = new_sf0;
            local_changed = 1;
        }
        if (cond1 && new_sf1 != sf1) {
            sce->sf_idx[i+1] = new_sf1;
            local_changed = 1;
        }
        if (cond2 && new_sf2 != sf2) {
            sce->sf_idx[i+2] = new_sf2;
            local_changed = 1;
        }
        if (cond3 && new_sf3 != sf3) {
            sce->sf_idx[i+3] = new_sf3;
            local_changed = 1;
        }

        used[i % 40] ^= (local_changed & cond0); 
    }
    if (local_changed) changed = 1;
}
