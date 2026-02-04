#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct GetBitContext {
    const uint8_t *buffer;
    const uint8_t *buffer_end;
    int index;
    int size_in_bits;
    int size_in_bits_plus8;
} GetBitContext;

typedef enum {
    I_F_Q = -1,
    SILENCE,
    RATE_OCTAVE,
    RATE_QUARTER,
    RATE_HALF,
    RATE_FULL
} qcelp_packet_rate;

typedef struct QCELPFrame {
    uint8_t cbsign[16];
    uint8_t cbgain[16];
    uint8_t cindex[16];
    uint8_t plag[4];
    uint8_t pfrac[4];
    uint8_t pgain[4];
    uint8_t lspv[10];
    uint8_t reserved;
} QCELPFrame;

typedef struct QCELPContext {
    GetBitContext gb;
    qcelp_packet_rate bitrate;
    QCELPFrame frame;
    uint8_t erasure_count;
    uint8_t octave_count;
    float prev_lspf[10];
    float predictor_lspf[10];
    float pitch_synthesis_filter_mem[303];
    float pitch_pre_filter_mem[303];
    float rnd_fir_filter_mem[180];
    float formant_mem[170];
    float last_codebook_gain;
    int prev_g1[2];
    int prev_bitrate;
    float pitch_gain[4];
    uint8_t pitch_lag[4];
    uint16_t first16bits;
    uint8_t warned_buf_mismatch_bitrate;
    float postfilter_synth_mem[10];
    float postfilter_agc_mem;
    float postfilter_tilt_mem;
} QCELPContext;

QCELPContext *q;
float *lspf;
int i;
float erasure_coeff;
float *predictors;

static uint8_t static_buffer[8192];
static float static_lspf[10];
static float static_predictors[10];

void init_vars() {
    q = (QCELPContext *)malloc(sizeof(QCELPContext));
    if (!q) exit(1);

    q->gb.buffer = static_buffer;
    q->gb.buffer_end = static_buffer + sizeof(static_buffer);
    q->gb.index = 0;
    q->gb.size_in_bits = 8 * sizeof(static_buffer);
    q->gb.size_in_bits_plus8 = q->gb.size_in_bits + 8;

    q->bitrate = RATE_FULL;
    q->erasure_count = 0;
    q->octave_count = 0;
    for (int j = 0; j < 10; j++) {
        q->prev_lspf[j] = 0.0f;
        q->predictor_lspf[j] = 0.0f;
    }
    for (int j = 0; j < 303; j++) {
        q->pitch_synthesis_filter_mem[j] = 0.0f;
        q->pitch_pre_filter_mem[j] = 0.0f;
    }
    for (int j = 0; j < 180; j++) {
        q->rnd_fir_filter_mem[j] = 0.0f;
    }
    for (int j = 0; j < 170; j++) {
        q->formant_mem[j] = 0.0f;
    }
    q->last_codebook_gain = 0.0f;
    q->prev_g1[0] = q->prev_g1[1] = 0;
    q->prev_bitrate = SILENCE;
    for (int j = 0; j < 4; j++) {
        q->pitch_gain[j] = 0.0f;
        q->pitch_lag[j] = 0;
    }
    q->first16bits = 0;
    q->warned_buf_mismatch_bitrate = 0;
    for (int j = 0; j < 10; j++) {
        q->postfilter_synth_mem[j] = 0.0f;
    }
    q->postfilter_agc_mem = 0.0f;
    q->postfilter_tilt_mem = 0.0f;

    lspf = static_lspf;
    predictors = static_predictors;
    for (int j = 0; j < 10; j++) {
        static_predictors[j] = j * 0.1f;
    }
    erasure_coeff = 0.2f;
    i = 0;
}