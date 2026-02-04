#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct AMRWBSubFrame {
    uint16_t adap;
    uint16_t ltp;
    uint16_t vq_gain;
    uint16_t hb_gain;
    uint16_t pul_ih[4];
    uint16_t pul_il[4];
} AMRWBSubFrame;

typedef struct AMRWBFrame {
    uint16_t vad;
    uint16_t isp_id[7];
    AMRWBSubFrame subframe[4];
} AMRWBFrame;

enum Mode {
    MODE_6k60 = 0,
    MODE_8k85,
    MODE_12k65,
    MODE_14k25,
    MODE_15k85,
    MODE_18k25,
    MODE_19k85,
    MODE_23k05,
    MODE_23k85,
    MODE_SID,
    SP_LOST = 14,
    NO_DATA
};

typedef struct AVLFG {
    unsigned int state[64];
    int index;
} AVLFG;

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

typedef struct AMRWBContext {
    AMRWBFrame frame;
    enum Mode fr_cur_mode;
    uint8_t fr_quality;
    float isf_cur[16];
    float isf_q_past[16];
    float isf_past_final[16];
    double isp[4][16];
    double isp_sub4_past[16];
    float lp_coef[4][16];
    uint8_t base_pitch_lag;
    uint8_t pitch_lag_int;
    float excitation_buf[313];
    float *excitation;
    float pitch_vector[64];
    float fixed_vector[64];
    float prediction_error[4];
    float pitch_gain[6];
    float fixed_gain[2];
    float tilt_coef;
    float prev_sparse_fixed_gain;
    uint8_t prev_ir_filter_nr;
    float prev_tr_gain;
    float samples_az[80];
    float samples_up[88];
    float samples_hb[100];
    float hpf_31_mem[2];
    float hpf_400_mem[2];
    float demph_mem[1];
    float bpf_6_7_mem[30];
    float lpf_7_mem[30];
    AVLFG prng;
    uint8_t first_frame;
    ACELPFContext acelpf_ctx;
    ACELPVContext acelpv_ctx;
    CELPFContext celpf_ctx;
    CELPMContext celpm_ctx;
} AMRWBContext;

AMRWBContext *ctx;
int i;
int count;

void init_vars() {
    ctx = (AMRWBContext*)calloc(1, sizeof(AMRWBContext));
    if (!ctx) exit(1);

    ctx->fr_cur_mode = MODE_6k60;
    ctx->fr_quality = 1;
    for (int j = 0; j < 16; j++) {
        ctx->isf_cur[j] = 0.1f * j;
        ctx->isf_q_past[j] = 0.1f * j;
        ctx->isf_past_final[j] = 0.1f * j;
        for (int k = 0; k < 4; k++)
            ctx->isp[k][j] = 0.1 * j + k;
        ctx->isp_sub4_past[j] = 0.1 * j;
        for (int k = 0; k < 4; k++)
            ctx->lp_coef[k][j] = 0.1f * j;
    }
    ctx->base_pitch_lag = 20;
    ctx->pitch_lag_int = 18;
    for (int j = 0; j < 313; j++)
        ctx->excitation_buf[j] = 0.0f;
    ctx->excitation = ctx->excitation_buf;
    for (int j = 0; j < 64; j++) {
        ctx->pitch_vector[j] = 0.5f;
        ctx->fixed_vector[j] = 0.3f;
    }
    for (int j = 0; j < 4; j++)
        ctx->prediction_error[j] = 0.1f;
    for (int j = 0; j < 6; j++)
        ctx->pitch_gain[j] = j < 3 ? 0.3f : 0.7f;
    for (int j = 0; j < 2; j++)
        ctx->fixed_gain[j] = 0.5f;
    ctx->tilt_coef = 0.2f;
    ctx->prev_sparse_fixed_gain = 0.4f;
    ctx->prev_ir_filter_nr = 1;
    ctx->prev_tr_gain = 0.6f;
    for (int j = 0; j < 80; j++)
        ctx->samples_az[j] = 0.1f * (j % 5);
    for (int j = 0; j < 88; j++)
        ctx->samples_up[j] = 0.1f * (j % 5);
    for (int j = 0; j < 100; j++)
        ctx->samples_hb[j] = 0.1f * (j % 5);
    for (int j = 0; j < 2; j++) {
        ctx->hpf_31_mem[j] = 0.0f;
        ctx->hpf_400_mem[j] = 0.0f;
    }
    ctx->demph_mem[0] = 0.0f;
    for (int j = 0; j < 30; j++) {
        ctx->bpf_6_7_mem[j] = 0.0f;
        ctx->lpf_7_mem[j] = 0.0f;
    }
    for (int j = 0; j < 64; j++)
        ctx->prng.state[j] = j * 12345U;
    ctx->prng.index = 0;
    ctx->first_frame = 1;

    i = 0;
    count = 0;
}