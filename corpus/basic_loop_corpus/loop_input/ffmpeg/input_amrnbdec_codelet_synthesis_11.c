#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct AMRNBSubframe {
    uint16_t p_lag;
    uint16_t p_gain;
    uint16_t fixed_gain;
    uint16_t pulses[10];
} AMRNBSubframe;

typedef struct AMRNBFrame {
    uint16_t lsf[5];
    AMRNBSubframe subframe[4];
} AMRNBFrame;

enum Mode {
    MODE_4k75 = 0,
    MODE_5k15,
    MODE_5k9,
    MODE_6k7,
    MODE_7k4,
    MODE_7k95,
    MODE_10k2,
    MODE_12k2,
    MODE_DTX,
    N_MODES,
    NO_DATA = 15
};

typedef struct ACELPFContext {
    void (*acelp_interpolatef)(float *, const float *, const float *, int, int, int, int);
    void (*acelp_apply_order_2_transfer_function)(float *, const float *, const float *, const float *, float, float *, int);
} ACELPFContext;

typedef struct ACELPVContext {
    void (*weighted_vector_sumf)(float *, const float *, const float *, float, float, int);
} ACELPVContext;

typedef struct CELPFContext {
    void (*celp_lp_synthesis_filterf)(float *, const float *, const float *, int, int);
    void (*celp_lp_zero_synthesis_filterf)(float *, const float *, const float *, int, int);
} CELPFContext;

typedef struct CELPMContext {
    float (*dot_productf)(const float *, const float *, int);
} CELPMContext;

typedef struct AMRContext {
    AMRNBFrame frame;
    uint8_t bad_frame_indicator;
    enum Mode cur_frame_mode;
    int16_t prev_lsf_r[10];
    double lsp[4][10];
    double prev_lsp_sub4[10];
    float lsf_q[4][10];
    float lsf_avg[10];
    float lpc[4][10];
    uint8_t pitch_lag_int;
    float excitation_buf[194];
    float *excitation;
    float pitch_vector[40];
    float fixed_vector[40];
    float prediction_error[4];
    float pitch_gain[5];
    float fixed_gain[5];
    float beta;
    uint8_t diff_count;
    uint8_t hang_count;
    float prev_sparse_fixed_gain;
    uint8_t prev_ir_filter_nr;
    uint8_t ir_filter_onset;
    float postfilter_mem[10];
    float tilt_mem;
    float postfilter_agc;
    float high_pass_mem[2];
    float samples_in[50];
    ACELPFContext acelpf_ctx;
    ACELPVContext acelpv_ctx;
    CELPFContext celpf_ctx;
    CELPMContext celpm_ctx;
} AMRContext;

AMRContext *p;
int i;
float excitation[40];
float pitch_factor;

void init_vars() {
    p = (AMRContext*)malloc(sizeof(AMRContext));
    if (!p) exit(1);

    p->bad_frame_indicator = 0;
    p->cur_frame_mode = MODE_12k2;
    p->pitch_lag_int = 20;
    p->beta = 0.7f;
    p->diff_count = 0;
    p->hang_count = 0;
    p->prev_sparse_fixed_gain = 1.0f;
    p->prev_ir_filter_nr = 0;
    p->ir_filter_onset = 0;
    p->tilt_mem = 0.0f;
    p->postfilter_agc = 1.0f;

    for (int j = 0; j < 10; j++) {
        p->prev_lsf_r[j] = 1000 + j * 100;
    }

    for (int j = 0; j < 4; j++) {
        for (int k = 0; k < 10; k++) {
            p->lsp[j][k] = 0.1 * (j + 1) * (k + 1);
            p->lsf_q[j][k] = 0.05f * (j + 1) * (k + 1);
            p->lpc[j][k] = 0.02f * (j + 1) * (k + 1);
        }
    }

    for (int j = 0; j < 10; j++) {
        p->prev_lsp_sub4[j] = 0.05 * j;
        p->lsf_avg[j] = 0.03f * j;
    }

    for (int j = 0; j < 194; j++) {
        p->excitation_buf[j] = (float)(rand()) / RAND_MAX * 2.0f - 1.0f;
    }

    for (int j = 0; j < 40; j++) {
        p->pitch_vector[j] = (float)(rand()) / RAND_MAX * 0.5f;
        p->fixed_vector[j] = (float)(rand()) / RAND_MAX * 0.8f;
    }

    for (int j = 0; j < 4; j++) {
        p->prediction_error[j] = 0.1f * (j + 1);
    }

    for (int j = 0; j < 5; j++) {
        p->pitch_gain[j] = 0.6f + j * 0.1f;
        p->fixed_gain[j] = 0.8f + j * 0.05f;
    }

    for (int j = 0; j < 10; j++) {
        p->postfilter_mem[j] = 0.0f;
    }

    for (int j = 0; j < 2; j++) {
        p->high_pass_mem[j] = 0.0f;
    }

    for (int j = 0; j < 50; j++) {
        p->samples_in[j] = (float)(rand()) / RAND_MAX * 2.0f - 1.0f;
    }

    p->excitation = p->excitation_buf + 154;

    for (int j = 0; j < 5; j++) {
        p->frame.lsf[j] = 1500 + j * 200;
    }

    for (int j = 0; j < 4; j++) {
        p->frame.subframe[j].p_lag = 20 + j;
        p->frame.subframe[j].p_gain = 30 + j;
        p->frame.subframe[j].fixed_gain = 40 + j;
        for (int k = 0; k < 10; k++) {
            p->frame.subframe[j].pulses[k] = k;
        }
    }

    for (int j = 0; j < 40; j++) {
        excitation[j] = (float)(rand()) / RAND_MAX * 2.0f - 1.0f;
    }

    pitch_factor = 0.75f;

    p->acelpf_ctx.acelp_interpolatef = NULL;
    p->acelpf_ctx.acelp_apply_order_2_transfer_function = NULL;
    p->acelpv_ctx.weighted_vector_sumf = NULL;
    p->celpf_ctx.celp_lp_synthesis_filterf = NULL;
    p->celpf_ctx.celp_lp_zero_synthesis_filterf = NULL;
    p->celpm_ctx.dot_productf = NULL;
}