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

static uint8_t global_buffer[1 << 20];
static uint8_t global_buffer_end[1 << 20];

QCELPContext *q;
int i;

void init_vars() {
    q = (QCELPContext*)calloc(1, sizeof(QCELPContext));
    if (!q) exit(1);

    q->gb.buffer = global_buffer;
    q->gb.buffer_end = global_buffer_end;
    q->gb.index = 0;
    q->gb.size_in_bits = 8 * (1 << 20);
    q->gb.size_in_bits_plus8 = q->gb.size_in_bits + 8;

    q->bitrate = SILENCE;

    for (int idx = 0; idx < 16; idx++) {
        q->frame.cbsign[idx] = idx % 2;
        q->frame.cbgain[idx] = idx * 5;
        q->frame.cindex[idx] = idx * 3;
    }

    for (int idx = 0; idx < 4; idx++) {
        q->frame.plag[idx] = idx % 3;
        q->frame.pfrac[idx] = idx * 10;
        q->frame.pgain[idx] = idx * 2;
    }

    for (int idx = 0; idx < 10; idx++) {
        q->frame.lspv[idx] = idx * 7;
    }
    q->frame.reserved = 0;

    q->erasure_count = 0;
    q->octave_count = 0;

    for (int idx = 0; idx < 10; idx++) {
        q->prev_lspf[idx] = 0.1f * idx;
        q->predictor_lspf[idx] = 0.05f * idx;
    }

    for (int idx = 0; idx < 303; idx++) {
        q->pitch_synthesis_filter_mem[idx] = 0.0f;
        q->pitch_pre_filter_mem[idx] = 0.0f;
    }

    for (int idx = 0; idx < 180; idx++) {
        q->rnd_fir_filter_mem[idx] = 0.0f;
    }

    for (int idx = 0; idx < 170; idx++) {
        q->formant_mem[idx] = 0.0f;
    }

    q->last_codebook_gain = 1.0f;

    q->prev_g1[0] = 1;
    q->prev_g1[1] = 2;

    q->prev_bitrate = SILENCE;

    for (int idx = 0; idx < 4; idx++) {
        q->pitch_gain[idx] = 0.0f;
        q->pitch_lag[idx] = 0;
    }

    q->first16bits = 0x1234;
    q->warned_buf_mismatch_bitrate = 0;

    for (int idx = 0; idx < 10; idx++) {
        q->postfilter_synth_mem[idx] = 0.0f;
    }

    q->postfilter_agc_mem = 1.0f;
    q->postfilter_tilt_mem = 0.5f;

    i = 0;
}